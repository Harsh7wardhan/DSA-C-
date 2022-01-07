// **********************************************method-1*********************************************************************
// // CPP program to find union and intersection
// // using sets
// #include <bits/stdc++.h>
// using namespace std;

// // Prints union of arr1[0..n1-1] and arr2[0..n2-1]
// void printUnion(int arr1[], int arr2[], int n1, int n2)
// {
//     set<int> hs;

//     // Insert the elements of arr1[] to set hs
//     for (int i = 0; i < n1; i++)
//         hs.insert(arr1[i]);

//     // Insert the elements of arr2[] to set hs
//     for (int i = 0; i < n2; i++)
//         hs.insert(arr2[i]);

//     // Print the content of set hs
//     for (auto it = hs.begin(); it != hs.end(); it++)
//         cout << *it << " ";
//     cout << endl;
// }

// // Prints intersection of arr1[0..n1-1] and
// // arr2[0..n2-1]
// void printIntersection(int arr1[], int arr2[], int n1,
//                        int n2)
// {
//     set<int> hs;

//     // Insert the elements of arr1[] to set S
//     for (int i = 0; i < n1; i++)
//         hs.insert(arr1[i]);

//     for (int i = 0; i < n2; i++)

//         // If element is present in set then
//         // push it to vector V
//         if (hs.find(arr2[i]) != hs.end())
//             cout << arr2[i] << " ";
// }

// // Driver Program
// int main()
// {
//     int arr1[] = { 7, 1, 5, 2, 3, 6 };
//     int arr2[] = { 3, 8, 6, 20, 7 };
//     int n1 = sizeof(arr1) / sizeof(arr1[0]);
//     int n2 = sizeof(arr2) / sizeof(arr2[0]);

//     // Function call
//     printUnion(arr1, arr2, n1, n2);
//     printIntersection(arr1, arr2, n1, n2);

//     return 0;
// }

// ********************************************************method-2************************************************************
// C++ program to find union of
// two sorted arrays
#include <bits/stdc++.h>
using namespace std;

/* Function prints union of arr1[] and arr2[]
m is the number of elements in arr1[]
n is the number of elements in arr2[] */
void printUnion(int arr1[], int arr2[], int m, int n)
{
	int i = 0, j = 0;
	while (i < m && j < n) {
		if (arr1[i] < arr2[j])
			cout << arr1[i++] << " ";

		else if (arr2[j] < arr1[i])
			cout << arr2[j++] << " ";

		else {
			cout << arr2[j++] << " ";
			i++;
		}
	}

	/* Print remaining elements of the larger array */
	while (i < m)
		cout << arr1[i++] << " ";

	while (j < n)
		cout << arr2[j++] << " ";
}

/* Driver program to test above function */
int main()
{
	int arr1[] = { 1, 2, 4, 5, 6 };
	int arr2[] = { 2, 3, 5, 7 };

	int m = sizeof(arr1) / sizeof(arr1[0]);
	int n = sizeof(arr2) / sizeof(arr2[0]);

	// Function calling
	printUnion(arr1, arr2, m, n);

	return 0;
}










// C++ program to find intersection of
// two sorted arrays
#include <bits/stdc++.h>
using namespace std;

/* Function prints Intersection of arr1[] and arr2[]
m is the number of elements in arr1[]
n is the number of elements in arr2[] */
void printIntersection(int arr1[], int arr2[], int m, int n)
{
	int i = 0, j = 0;
	while (i < m && j < n) {
		if (arr1[i] < arr2[j])
			i++;
		else if (arr2[j] < arr1[i])
			j++;
		else /* if arr1[i] == arr2[j] */
		{
			cout << arr2[j] << " ";
			i++;
			j++;
		}
	}
}

/* Driver program to test above function */
int main()
{
	int arr1[] = { 1, 2, 4, 5, 6 };
	int arr2[] = { 2, 3, 5, 7 };

	int m = sizeof(arr1) / sizeof(arr1[0]);
	int n = sizeof(arr2) / sizeof(arr2[0]);

	// Function calling
	printIntersection(arr1, arr2, m, n);

	return 0;
}
