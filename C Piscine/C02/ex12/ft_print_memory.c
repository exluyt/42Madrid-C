/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:23:14 by akiss             #+#    #+#             */
/*   Updated: 2024/07/15 20:31:26 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define MAX_PAGE_SIZE 14

// Converts a number to a specified base and stores the result in a buffer array recursively.
void	ft_buffer_number(unsigned long long number, int radix, int buffer[], int index)
{
    if (number > (unsigned long long)(radix - 1))
        ft_buffer_number(number / radix, radix, buffer, index + 1);
    buffer[index] = number % radix;
}

// Prints a number in hexadecimal format.
void	ft_write_hex(unsigned long long number, int radix, int char_count)
{
    int	buffer[MAX_PAGE_SIZE + 1];
    int	index;

    index = -1;
    while (index++ < MAX_PAGE_SIZE)
        buffer[index] = 0;
    ft_buffer_number(number, radix, buffer, 0);
    index = -1;
    while (++index < char_count)
        write(1, &"0123456789abcdef"[buffer[char_count - 1 - index]], 1);
}

// Prints a character if it's printable; otherwise, prints a dot.
void	ft_write_safe_char(char *c)
{
    if (*c >= ' ' && *c != 127)
        write(1, c, 1);
    else
        write(1, ".", 1);
}

// Prints the memory content at a given address in hexadecimal and ASCII.
void	ft_print_memory_at(void *start_addr, unsigned int size, char *curr_addr)
{
    int	index;

    ft_write_hex((unsigned long long)curr_addr, 16, MAX_PAGE_SIZE);
    write(1, ": ", 2);
    index = 0;
    while (index < 16)
    {
        if ((unsigned long long)(start_addr + size) <=
            (unsigned long long)(curr_addr + index))
            write(1, "  ", 2);
        else
            ft_write_hex((unsigned char)*(curr_addr + index), 16, 2);
        if (index % 2 == 1)
            write(1, " ", 1);
        index++;
    }
    write(1, " ", 1);
    index = 0;
    while (index < 16)
    {
        if ((unsigned long long)(start_addr + size) >
            (unsigned long long)(curr_addr + index))
            ft_write_safe_char(curr_addr + index);
        index++;
    }
}

// Iterates over a block of memory and prints its content.
void	*ft_print_memory(void *addr, unsigned int size)
{
    char	*curr_addr;

    curr_addr = (char *)addr;
    while ((unsigned long long)curr_addr < (unsigned long long)(addr + size))
    {
        ft_print_memory_at(addr, size, curr_addr);
        write(1, "\n", 1);
        curr_addr += 16;
    }
    return (addr);
}
/*
int main()
{
	char *str = "Bonjour les aminches\t\n\tc est fou.tout.ce qu on peut faire avec...print_memory....lol.lol. ";
	ft_print_memory(str, 92);
	return 0;
}
*/
