# Ylib - C Standard library

![GitHub commit activity](https://img.shields.io/github/commit-activity/t/yuann3/Ylib) ![GitHub repo size](https://img.shields.io/github/repo-size/yuann3/Ylib) [![.github/workflows/norminette](https://github.com/yuann3/Ylib/actions/workflows/norminette.yml/badge.svg)](https://github.com/yuann3/Ylib/actions/workflows/norminette.yml)


We're reinventing the wheel, Ylib is a rewrite of the C standard library and is part of the 42@SUTD course. It contains string type checking, memory management, etc...(continually updated)

## List of Functions

The repository is still in the early stages of development, and the following is a list of functions that are in the process of being implemented


| **Status** | **Name**        | **Description**                                   | **Status** | **Name**     | **Description**                        |
| ---------- | --------------- | ------------------------------------------------- | ---------- | ------------ | -------------------------------------- |
| ✅          | **_FT_IS_**     | _functions for checking character types_          | 🟨          | **_FT_MEM_** | _functions for memory management_      |
| ✅          | ft_isalpha      |                                                   | ✅          | ft_memset    |                                        |
| ✅          | ft_isdigit      |                                                   | ✅          | ft_memmove   |                                        |
| ✅          | ft_isalnum      |                                                   | ✅          | ft_memcpy    |                                        |
| ✅          | ft_isascii      |                                                   | ✅          | ft_memcmp    |                                        |
| ✅          | ft_isprint      |                                                   | 🔲          | ft_memchr    |                                        |
|            |                 |                                                   | 🔲          | ft_calloc    |                                        |
|            |                 |                                                   | 🔲          | ft_bzero     |                                        |
| **Status** | **Name**        | **Description**                                   | **Status** | **Name**     | **Description**                        |
| 🔲          | **_FT_LST_**    | _functions that manipulating linked lists_        | ✅          | **_FT_STR_** | _functions that are related to string_ |
| 🔲          | ft_lstadd_back  |                                                   | ✅          | ft_strlen    |                                        |
| 🔲          | ft_lstadd_front |                                                   | ✅          | ft_strlcpy   |                                        |
| 🔲          | ft_lstclear     |                                                   | ✅          | ft_strlcat   |                                        |
| 🔲          | ft_lstdelone    |                                                   | ✅          | ft_toupper   |                                        |
| 🔲          | ft_lstiter      |                                                   | ✅          | ft_tolower   |                                        |
| 🔲          | ft_lstlast      |                                                   | ✅          | ft_strchr    |                                        |
| 🔲          | ft_lstmap       |                                                   | ✅          | ft_strncmp   |                                        |
| 🔲          | ft_lstnew       |                                                   | ✅          | ft_strnstr   |                                        |
| 🔲          | ft_lstsize      |                                                   | ✅          | ft_atoi      |                                        |
|            |                 |                                                   | ✅          | ft_strdup    |                                        |
| **Status** | **Name**        | **Description**                                   | ✅          | ft_striteri  |                                        |
| ✅          | **_FT_PUT_**    | _functions for outputting characters and strings_ | ✅          | ft_strmapi   |                                        |
| ✅          | ft_putchar_fd   |                                                   | ✅          | ft_itoa      |                                        |
| ✅          | ft_putstr_fd    |                                                   | ✅          | ft_split     |                                        |
| ✅          | ft_putendl_fd   |                                                   | ✅          | ft_strtrim   |                                        |
| ✅          | ft_putnbr_fd    |                                                   | ✅          | ft_strjoin   |                                        |
|            |                 |                                                   | ✅          | ft_substr    |                                        |
|            |                 |                                                   | ✅          | ft_strrchr   |                                        |