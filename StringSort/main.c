/**
 * @file main.c
 * @author Ben Rosenberg
 * @brief String sorting and comparison functions
 * @version 0.1
 * @date 2023-02-25
 * 
 * String sorting algorithm--bubble sort--along with a number of different
 * string comparison functions.
 */

#include <stdio.h>
#include <stdbool.h>

// Utility functions
void print_str_arr(char**, const int);
int get_num_chars(const char*);
int get_num_distinct_chars(const char*);

// Comparison functions
int lexicographic_cmp(const char*, const char*);
int lexicographic_cmp_reverse(const char*, const char*);
int distinct_characters_cmp(const char*, const char*);
int length_cmp(const char*, const char*);

// Sorting function
void string_sort(char**, const int, int (*)(const char*, const char*));


int main(int argc, char* argv[])
{
    char* a1 = "hello";
    char* b1 = "help";
    char* c = "god";
    char* d = "gods";
    char* e = "godbless";
    char* f = "bit";

    char* arr[6] = {a1, b1, c, d, e, f};

    char* arr2[42] = {
        "ibahqaceux",
        "prmv",
        "ovsylj",
        "ta",
        "eovfkgikn",
        "mrhgpexi",
        "s",
        "gqrhdd",
        "wfy",
        "uwhgessrv",
        "kcm",
        "gl",
        "zgjhycobhl",
        "njzjhi",
        "lchexnrzbs",
        "mch",
        "n",
        "srftz",
        "umbtxle",
        "ygvfe",
        "wfnonbs",
        "wfnqxsmwk",
        "k",
        "ajwgxxou",
        "u",
        "yatmpuf",
        "qmbhl",
        "vjfbvq",
        "epjboyvq",
        "bouuckp",
        "yhyzqjsltz",
        "opqtgauu",
        "smstanofz",
        "qxmowfyq",
        "t",
        "fhgwcp",
        "zjyrysk",
        "hafgh",
        "f",
        "kbbkt",
        "dk",
        "lrvn"
    };

    printf("before:\n\n");
    print_str_arr(arr2, 42);

    printf("\n\nafter:\n\n");
    string_sort(arr2, 42, lexicographic_cmp);
    print_str_arr(arr2, 42);
    
    return 0;
}


// Utility functions

void print_str_arr(char** arr, const int len)
{
    for (int i = 0; i < len; ++i)
        printf("%s\n", arr[i]);
}

int get_num_chars(const char* str)
{
    int len = 0;

    while (str[len] != '\0')
        ++len;
    
    return len;
}

int get_num_distinct_chars(const char* str)
{
    int num_distinct_chars = 0;
    bool char_set[26] = {false};

    for (int i = 0; str[i] != '\0'; ++i) {
        num_distinct_chars += (!char_set[str[i] - 97]) ? 1 : 0;
        char_set[str[i] - 97] = true;
    }
    
    return num_distinct_chars;
}

// Comparison functions

int lexicographic_cmp(const char* a, const char* b)
{
    int cmp_idx = 0;

    while (a[cmp_idx] == b[cmp_idx] && a[cmp_idx] != '\0' && b[cmp_idx] != '\0')
        ++cmp_idx;
    
    if (a[cmp_idx] < b[cmp_idx])
        return -1;
    if (a[cmp_idx] > b[cmp_idx])
        return 1;
    
    return 0;
}

int lexicographic_cmp_reverse(const char* a, const char* b)
{
    return lexicographic_cmp(a, b) * -1;
}

int distinct_characters_cmp(const char* a, const char* b)
{
    int a_num_distinct = get_num_distinct_chars(a);
    int b_num_distinct = get_num_distinct_chars(b);

    if (a_num_distinct < b_num_distinct)
        return -1;
    
    if (a_num_distinct > b_num_distinct)
        return 1;
    
    return lexicographic_cmp(a, b);
}

int length_cmp(const char* a, const char* b)
{
    int len_a = get_num_chars(a);
    int len_b = get_num_chars(b);

    if (len_a < len_b)
        return -1;
    if (len_a > len_b)
        return 1;

    return lexicographic_cmp(a, b);
}

// Sorting function

void string_sort(char** arr, const int len, int (*cmp)(const char* a, const char* b))
{
    for (int unsorted_count = len; unsorted_count > 0; --unsorted_count)
    {
        int greatest_remaining = 0;
        for (int i = 1; i < unsorted_count; ++i)
        {
            if (cmp(arr[i], arr[greatest_remaining]) > 0)
                greatest_remaining = i;
        }

        char* temp = arr[unsorted_count - 1];
        arr[unsorted_count - 1] = arr[greatest_remaining];
        arr[greatest_remaining] = temp;
    }
}
