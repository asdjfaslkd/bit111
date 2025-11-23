#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//#include<string.h>
//#include<assert.h>

// 字符转换
//int main()
//{
//	int ret = toupper('a');//小写字母转大写
//	printf("%c\n", ret);
//	ret = tolower(ret);//大写字母转小写
//	printf("%c\n", ret);
//	return 0;
//}

// 把字符串全部改成小写
//int main()
//{
//	char arr[] = "Test String.\n";
//	char* p = arr;
//	while (*p)
//	{
//		if (isupper(*p))
//		{
//			*p = tolower(*p);
//		}
//		p++;
//	}
//	printf("%s", arr);
//	return 0;
//}


// 模拟实现memcpy
//void* my_memcpy(void* dest, const void* src, size_t sz)
//{
//	assert(dest && src);
//	void* ret = dest;
//	while (sz--)
//	{
//		*(char*)dest = *(char*)src;
//		dest = (char*)dest + 1;
//		src = (char*)src + 1; 
//	}
//	return ret;
//}
//int main()
//{
//	int arr1[10] = { 0 };
//	int arr2[] = { 1,2,3,4,5 };
//	// 把arr2中的前5个整数的数据 拷贝放在arr1中
//	my_memcpy(arr1, arr2, 20);
//	return 0;
//}
//

// 模拟实现memmove
//void* my_memmove(void* dest, const void* src, size_t sz)
//{
//	assert(dest && src);
//	void* ret = dest;
//	if (dest < src)
//	{
//		// 前->后
//		while (sz--)
//		{
//			*(char*)dest = *(char*)src;
//			dest = (char*)dest + 1;
//			src = (char*)src + 1;
//		}
//	}
//	else
//	{
//		// 后->前
//		while (sz--)
//		{
//			*((char*)dest + sz) = *((char*)src + sz);
//		}
//	}
//	return ret;
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	my_memmove(arr + 2, arr, 20);
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}



#include<stdio.h>
#include<stdlib.h>

//int main()
//{
//	// 申请一块空间,用来存放10个整形
//	// malloc 
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (p == NULL)
//	{
//		perror("malloc");
//		return 1;
//	}
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", p[i]);
//	}
//
//	free(p);
//	p = NULL;
//	return 0;
//}

int main()
{
	int* p = (int*)calloc(10, sizeof(int));
	if (p == NULL)
	{
		perror("calloc");
		return 1;
	}
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", *(p + i));
	}
	free(p);
	p = NULL;
	return 0;
}