#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

void check_elf(unsigned char *e_ident)
{
    int index;

    for (index = 0; index < 4; index++)
    {
        if (e_ident[index] != 127 &&
            e_ident[index] != 'E' &&
            e_ident[index] != 'L' &&
            e_ident[index] != 'F')
        {
            dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
            exit(98);
        }
    }
}

void print_magic(unsigned char *e_ident)
{
    int index;

    printf("  Magic:   ");

    for (index = 0; index < EI_NIDENT; index++)
    {
        printf("%02x", e_ident[index]);

        if (index == EI_NIDENT - 1)
            printf("\n");
        else
            printf(" ");
    }
}

void print_class(unsigned char *e_ident)
{
    printf("  Class:                             ");

    switch (e_ident[EI_CLASS])
    {
    case ELFCLASSNONE:
        printf("none\n");
        break;
    case ELFCLASS32:
        printf("ELF32\n");
        break;
    case ELFCLASS64:
        printf("ELF64\n");
        break;
    default:
        printf("<unknown: %x>\n", e_ident[EI_CLASS]);
    }
}

void print_data(unsigned char *e_ident)
{
    printf("  Data:                              ");

    switch (e_ident[EI_DATA])
    {
    case ELFDATANONE:
        printf("none\n");
        break;
    case ELFDATA2LSB:
        printf("2's complement, little endian\n");
        break;
    case ELFDATA2MSB:
        printf("2's complement, big endian\n");
        break;
    default:
        printf("<unknown: %x>\n", e_ident[EI_DATA]);
    }
}

void print_version(unsigned char *e_ident)
{
    printf("  Version:                           %d",
           e_ident[EI_VERSION]);

    switch (e_ident[EI_VERSION])
    {
    case EV_CURRENT:
        printf(" (current)\n");
        break;
    default:
        printf("\n");
        break;
    }
}

void print_osabi(unsigned char *e_ident)
{
    printf("  OS/ABI:                            ");

    switch (e_ident[EI_OSABI])
    {
    case ELFOSABI_NONE:
        printf("UNIX - System V\n");
        break;
    case ELFOSABI_HPUX:
        printf("UNIX - HP-UX\n");
        break;
    case ELFOSABI_NETBSD:
        printf("UNIX - NetBSD\n");
        break;
    case ELFOSABI_LINUX:
        printf("UNIX - Linux\n");
        break;
    case ELFOSABI_SOLARIS:
        printf("UNIX - Solaris\n");
        break;
    case ELFOSABI_IRIX:
        printf("UNIX - IRIX\n");
        break;
    case ELFOSABI_FREEBSD:
        printf("UNIX - FreeBSD\n");
        break;
    case ELFOSABI_TRU64:
        printf("UNIX - TRU64\n");
        break;
    case ELFOSABI_ARM:
        printf("ARM\n");
        break;
    case ELFOSABI_STANDALONE:
        printf("Standalone App\n");
        break;
    default:
        printf("<unknown: %x>\n", e_ident[EI_OSABI]);
    }
}

void print_abi(unsigned char *e_ident)
{
    printf("  ABI Version:                       %d\n",
           e_ident[EI_ABIVERSION]);
}

void print_type(unsigned int e_type, unsigned char *e_ident)
{
    if (e_ident[EI_DATA] == ELFDATA2MSB)
        e_type >>= 8;

    printf("  Type:                              ");

    switch (e_type)
    {
    case ET_NONE:
        printf("NONE (None)\n");
        break;
    case ET_REL:
        printf("REL (Relocatable file)\n");
        break;
    case ET_EXEC:
        printf("EXEC (Executable file)\n");
        break;
    case ET_DYN:
        printf("DYN (Shared object file)\n");
        break;
    case ET_CORE:
        printf("CORE (Core file)\n");
        break;
    default:
        printf("<unknown: %x>\n", e_type);
    }
}

void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
    printf("  Entry point address:               ");

    if (e_ident[EI_DATA] == ELFDATA2MSB)
    {
        e_entry = ((e_entry << 8) & 0xFF00FF00) |
                  ((e_entry >> 8) & 0xFF00FF);
        e_entry = (e_entry << 16) | (e_entry >> 16);
    }

    if (e_ident[EI_CLASS] == ELFCLASS32)
        printf("%#x\n", (unsigned int)e_entry);

    else
        printf("%#lx\n", e_entry);
}

void close_elf(int elf)
{
    if (close(elf) == -1)
    {
        dprintf(STDERR_FILENO,
                "Error: Can't close fd %d\n", elf);
        exit(98);
    }
}

int main(int __attribute__((__unused__)) argc, char *argv[])
{
    Elf32_Ehdr *header32;
    Elf64_Ehdr *header64;
    int o, r;
    int is_32bit = 0;
    int is_64bit = 0;

    o = open(argv[1], O_RDONLY);
    if (o == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
        exit(98);
    }

   
    header32 = malloc(sizeof(Elf32_Ehdr));
    header64 = malloc(sizeof(Elf64_Ehdr));
    if (header32 == NULL || header64 == NULL)
    {
        close_elf(o);
        dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
        exit(98);
    }

    r = read(o, header32, sizeof(Elf32_Ehdr));
    if (r == -1)
    {
        close_elf(o);
        free(header32);
        free(header64);
        dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
        exit(98);
    }

    if (header32->e_ident[EI_MAG0] == ELFMAG0 && header32->e_ident[EI_MAG1] == ELFMAG1 &&
        header32->e_ident[EI_MAG2] == ELFMAG2 && header32->e_ident[EI_MAG3] == ELFMAG3)
    {
        is_32bit = 1;
    }
   
    else if (header64->e_ident[EI_MAG0] == ELFMAG0 && header64->e_ident[EI_MAG1] == ELFMAG1 &&
             header64->e_ident[EI_MAG2] == ELFMAG2 && header64->e_ident[EI_MAG3] == ELFMAG3)
    {
        is_64bit = 1;
    }

    if (!(is_32bit || is_64bit))
    {
        close_elf(o);
        free(header32);
        free(header64);
        dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
        exit(98);
    }

    if (is_32bit)
    {
        check_elf(header32->e_ident);
        printf("ELF Header:\n");
        print_magic(header32->e_ident);
        print_class(header32->e_ident);
        print_data(header32->e_ident);
        print_version(header32->e_ident);
        print_osabi(header32->e_ident);
        print_abi(header32->e_ident);
        print_type(header32->e_type, header32->e_ident);
        print_entry(header32->e_entry, header32->e_ident);
    }
    else
    {
        check_elf(header64->e_ident);
        printf("ELF Header:\n");
        print_magic(header64->e_ident);
        print_class(header64->e_ident);
        print_data(header64->e_ident);
        print_version(header64->e_ident);
        print_osabi(header64->e_ident);
        print_abi(header64->e_ident);
        print_type(header64->e_type, header64->e_ident);
        print_entry(header64->e_entry, header64->e_ident);
    }

    free(header32);
    free(header64);
    close_elf(o);
    return (0);
}

