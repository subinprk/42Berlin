/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:12:39 by subpark           #+#    #+#             */
/*   Updated: 2023/05/11 13:55:15 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int is_set_start(char c, const char *set) {
    while (*set) {
        if (c == *set)
            return 1;
        set++;
    }
    return 0;
}

int is_set_end(char c, const char *set) {
    return is_set_start(c, set);
}

char *ft_strtrim(char const *s1, char const *set) {
    if (s1 == NULL || set == NULL)
        return NULL;

    const char *start = s1;
    const char *end = s1 + ft_strlen(s1) - 1;

    while (*start && is_set_start(*start, set))
        start++;

    while (end > start && is_set_end(*end, set))
        end--;

    size_t trimmed_length = end - start + 1;
    char *trimmed_str = (char *)malloc(trimmed_length + 1);

    if (trimmed_str == NULL)
        return NULL;

    ft_strlcpy(trimmed_str, start, trimmed_length);
    trimmed_str[trimmed_length] = '\0';

    return trimmed_str;
}
