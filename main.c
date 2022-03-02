#include "../libft.h"
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>


#define toBool(b) ((b) ? "true" : "false")
void print_test_message(char *test_name)
{
	printf(".----------------------------------------.\n");
	printf("||||||||| testing %s   \n", test_name);
	printf(".----------------------------------------.\n");
}

void print_count_correct_answers(int count, int should_be)
{
	printf(" -> from %d tests %d correct\n", should_be, count);
}

void test_bool_ft(int (*ft)(int));
void test_memmove(size_t len);
void test_atoi();
void test_bzero();
void test_calloc();
void test_itoa();
void test_memchr();
void test_memcmp();
void test_strchr();
void test_strdup();
void test_striteri();
void test_strjoin();
void test_strcmp();
void test_substr();
char **split(char *string, const char delimiter);

// gcc -Werror -Wextra -Wall main.c ../ft_isalpha.c ../ft_isalnum.c ../ft_isdigit.c ../ft_isascii.c ../ft_isprint.c ../ft_strlen.c
int main() {
	//test_bool_ft(&ft_isalpha);
	//test_bool_ft(&ft_isalnum);
	//test_bool_ft(&ft_isdigit);
	//test_bool_ft(&ft_isascii); //to see if its work increment i > 128
	//test_bool_ft(&ft_isprint);
	//printf("%zu", ft_strlen("h"));
	//test_memmove(9);
	//test_atoi();
	//test_bzero();
	//test_calloc();
	//test_itoa();
	//test_memchr();
	//test_memcmp();
	//test_strchr();
	//test_strdup();
	//test_striteri();
	//test_strjoin();
	//test_strcmp();
	//test_substr();
	char **tab = split("hello niga", ' ');
	printf("%s\n", tab[0]);
	printf("%s\n", tab[1]);


  return (0);
}

char **split(char *string, const char delimiter) {
    int length = 0, count = 0, i = 0, j = 0;
    while(*(string++)) {
        if (*string == delimiter) count++;
        length++;
    }
    string -= (length + 1); // string was incremented one more than length
    char **array = (char **)malloc(sizeof(char *) * (length + 1));
    char ** base = array;
    for(i = 0; i < (count + 1); i++) {
        j = 0;
        while(string[j] != delimiter) j++;
        j++;
        *array = (char *)malloc(sizeof(char) * j);
        memcpy(*array, string, (j-1));
        (*array)[j-1] = '\0';
        string += j;
        array++;
    }
    *array = 0;
    return base;  
}

void test_substr()
{
	print_test_message("substr");
	char *data = "123 \t \n \\this 'hello' is my string";
	int nums[9][2] = {
		{1, 2},
		{-1, 4},
		{-5, 4},
		{10, 5},
		{0, 0},
		{6, 0},
		{0, 6},
		{100, -435},
		{2, 8},
	};
	
	for (int i = 0; i < 9; i++){
		printf("search: hello - start: %d - len: %d - str: '%s'\n",
				nums[i][0],
				nums[i][1],
				ft_substr(data, nums[i][0], nums[i][1]));
		printf("\n");
	}
}

void test_strcmp() {
	print_test_message("strncmp");
	char data[12][100]= {
		"1335sdgfhHDD",
		"1335sdgfhHDDFJ",

		"hello this is me",
		"hello this is you",

		"1234567890",
		"1234567890",

		"\0",
		"",

		"\t\t",
		"\t",

		"\n",
		" \n"
		
	};
	int correct_answers = 0;
	int datalen = sizeof(data) / sizeof(data[0]);

	for (int i = 0; i < (int)datalen; i += 2)
	{
		int my_res = ft_strncmp (data[i], data[i+1], 10);
		int res = strncmp (data[i], data[i+1], 10);

		if (my_res == res)
			correct_answers++;
		//printf("my - %d\n", my_res);
		//printf("sh - %d\n", res);
	}
	print_count_correct_answers(correct_answers, 6);
}

void test_strjoin()
{
	print_test_message("strjoin");
	//int correct_answers = 0;
	char test_data[14][100] = {
		"str1  : 2034лыовра834sdfj",
		"str2  : ---234-234234--234sijdlf2o3u4.",
		"str3  :		sd----fsdlflkjsdf_____234u234udsf",
		"str4  : -++_+_+_+-234234--2342-34--23-4-23-4-23",
		"str5  : jsdhfuihewhfsdfsidf f2342 s   sdn           sdf234",
		"str6  : @@@@@----23",
		"str7  : 42038429342",
		"str8  :				---+3434",
		"str9  : ------------------------3",
		"str10 : ++++++++++++++++++++7g7",
		"str11 : >>>>>>.,<<><><>><><.24234",
		"str12 : sf98romwuf0x*&(EF)",
		"str13 :		  		  		    ++++__-34",
		"\0"
	};
	char test_data1[14][100] = {
		" with @ test string 1\n@ 4234 555",
		" with @ strin 2 ..sdf\t \r      skdfjs dfsdfio ",
		" with @ string 3 @@@980938420934",
		" with @ hello this is my string 2348\t\t\t\t",
		" with @ 48508459845984584598",
		" with @ @@@@@----23",
		" with @ 42038429342",
		" with @				---+3434",
		" with @ ------------------------3",
		" with @ ++++++++++++++++++++7g7",
		" with @ >>>>>>.,<<><><>><><.24234",
		"",
		"		  		  		    ++++__-34",
		"\0"
	};

	for (int i = 0; i < 14; i++){
		char *myresult = ft_strjoin(test_data[i], test_data1[i]);
		printf("result: %s\n", myresult);
	}

}

static void test_func_for_striteri(unsigned int i, char *str)
{
	i++;
	printf("-%c", ft_toupper((int)*str));
	//printf(" -- %c\n", *str);
}

void test_striteri() {
	char *str = "hello this is me";
	printf("before changes: %s\n", str);
	printf("after changes: ");
	ft_striteri(str, &test_func_for_striteri);
}


void test_strdup() {
	print_test_message("strdup");
	char test_data[14][100] = {
		"2034лыовра834sdfj",
		"---234-234234--234sijdlf2o3u4.",
		"		sd----fsdlflkjsdf_____234u234udsf",
		"-+++++-++_+_+_+-234234--2342-34--23-4-23-4-23",
		"jsdhfuihewhfsdfsidf f2342 s   sdn           sdf234",
		"@@@@@----23",
		"42038429342",
		"				---+3434",
		"------------------------3",
		"++++++++++++++++++++7g7",
		">>>>>>.,<<><><>><><.24234",
		"sf98romwuf0x*&(EF)",
		"		  		  		    ++++__-34",
		"\0"
	};
	int correct_answers = 0;

	for (int i = 0; i < 14; i++) {
		char *my_copy = ft_strdup(test_data[i]);
		char *copy = strdup(test_data[i]);

		if (ft_strlen(my_copy) == ft_strlen(copy))
			correct_answers++;
		//printf("copy = %s\n", my_copy);
		//printf("copy = %s\n", copy);
		//printf("len str = %zu\n", ft_strlen(my_copy));
		//printf("len copy = %zu\n", ft_strlen(copy));
	}
	print_count_correct_answers(correct_answers, 14);
}

void test_strchr() {
	print_test_message("strchr");
	const char *str = "Hi this is very long string i create it to find some character";
	char *search = "@#44AbsIFljdfi#)sjdDFJASD0#$Lllsdfopogib";
	int	correct_answers = 0;
	for (size_t i = 0; i < ft_strlen(search); i++) {
		char *my_elem = ft_strchr(str, search[i]);
		char *elem = strchr(str, search[i]);
		if (my_elem == elem)
			correct_answers++;
		//printf("test-%lu answ: %s\n", i, toBool(my_elem == elem));
	}
	print_count_correct_answers(correct_answers, (int)ft_strlen(search));
}

void test_memcmp() {
	print_test_message("memcmp");
	char *src = "A234567890";
   	char *dst = "A234567890";
	printf("my result: %d\n", ft_memcmp(src, dst, 10));
	printf("result: %d\n", memcmp(src, dst, 10));
}


void test_memchr() {
	print_test_message("memchr");
	char *str = "BIDFIJRLVJIslkdjfoierwjr(@*#&(#^@#_!@#;'][[{]}/\\]]'))1234567890";
	char *search = "AJ(@*#%)'04321O";
	int str_len = ft_strlen(str);
	int correct_answers = 0;

	for (int i = 0; i < str_len; i++)
	{
		char *sym = ft_memchr(str, search[i], str_len);
		char *sym1 = memchr(str, search[i], str_len);
		if (sym == sym1)
			correct_answers++;
		//printf("test-%d answ: %s", i, toBool(sym == sym1));
	}
	print_count_correct_answers(correct_answers, str_len);
}

void test_itoa() {
	print_test_message("itoa");
    int value[] = {
		11184810, -25, 64, 127,
		434, 3, 1260588259, 0,
	};
 
    for (int i = 0; i < 8; i++)
    {
        printf("itoa(%d) = %s\n", value[i], ft_itoa(value[i]));
    }
}

void test_calloc() {
	print_test_message("calloc");
	char *str = ft_calloc(4, sizeof(int));
	printf("size of str: %lu\n", sizeof(str));
	char *str1 = calloc(4, sizeof(int));
	printf("size of str: %lu\n", sizeof(str1));

	printf("equal? : %d\n", sizeof(str) == sizeof(str1));
}

void test_bzero() {
	print_test_message("bzero");
	char str[60]; // = "hello you are greate";
	printf("bzero test result: %lu\n", sizeof(str));
	ft_bzero(str, 5);
	printf("bzero test result: %lu\n", sizeof(str));
	printf("bzero test result: %s-\n", str);

	char str1[60]; // = "hello you are greate";
	printf("bzero test result: %lu\n", sizeof(str1));
	bzero(str, 5);
	printf("bzero test result: %lu\n", sizeof(str1));
	printf("bzero test result: %s-\n", str1);
}

void test_atoi() {
	print_test_message("atoi");
	char test_data[13][100] = {
		"2034лыовра834sdfj",
		"---234-234234--234sijdlf2o3u4.",
		"		sd----fsdlflkjsdf_____234u234udsf",
		"-+++++-++_+_+_+-234234--2342-34--23-4-23-4-23",
		"jsdhfuihewhfsdfsidf f2342 s   sdn           sdf234",
		"@@@@@----23",
		"42038429342",
		"				---+3434",
		"------------------------3",
		"++++++++++++++++++++7g7",
		">>>>>>.,<<><><>><><.24234",
		"sf98romwuf0x*&(EF)",
		"		  		  		    ++++__-34"
	};

	for (int i = 0; i < 13; i++) {
		int my_ft = ft_atoi(test_data[i]);
		int ft = atoi(test_data[i]);
		printf("answ: %d\n", (my_ft == ft));
	}
}

void test_bool_ft(int (*ft)(int)) {
	print_test_message("bool fts");
  // can test all functions with get bool response
	  for(int i = 0; i <= 127; i++) {
		char* resp = (*ft)(i) == 1 ? "True" : "False";
		printf("%c -> %s\n", i, resp);
  	}
}

void test_memmove(size_t len) {
	print_test_message("memmove");
	#define DST "hello this is my name: Amir"
	#define SRC "goodby i will go"

	char dest1[] = DST;
	const char src1[] = SRC;
	printf("Before testing:\n dest = %s,\n src = %s\n", dest1, src1);
	ft_memmove(dest1, src1, len);
	printf("After testing:\n dest = %s,\n src = %s\n", dest1, src1);

	printf("\n");
	char dest2[] = DST;
	const char src2[] = SRC;
	printf("Before testing:\n dest = %s,\n src = %s\n", dest2, src2);
	memmove(dest2, src2, len);
	printf("After testing:\n dest = %s,\n src = %s\n", dest2, src2);
	printf("%d", (*dest1 == *dest2));

}
