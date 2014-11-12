#include <stdio.h>
#include <stdlib.h>

/* mergesort*/
void mergesort(int a[], int l, int r);
void merge(int a[], int l, int m, int r);

/*quicksort*/
void quicksort(int a[], int l, int r);
int partition(int a[], int l, int r);

/*shellsort*/
void shellsort(int a[], int l, int r);

/*heapsort*/
void heapsort(int a[], int l, int r);
void adjust(int a[], int l, int r);

/*testcase*/
int main()
{
	int a[10] = {5, 7, 2, 11, 67, 0, 11,56, 100, 1};
	heapsort(a, 0, 9);
	for(int i = 0; i < 10; i++)
		printf("%d ",a[i]);
	system("pause");
	return 0;
}

/*mergesort*/
void mergesort(int a[], int l, int r)
{   
    if (r <= l)
       return;
	int m = (l+r)/2;
	mergesort(a, l, m);
	mergesort(a, m+1, r);
	merge(a, l, m, r);
}

void merge(int a[], int l, int m, int r)
{
	int k;
	int i = l;
	int j = m+1;
	int q = l;
	int aux[10];
	for (k = l; k <= r; k++)
		aux[k] = a[k];
	while (i <= m && j <= r)
	{
		if (aux[i] <= aux[j])
		{
			a[q++] = aux[i];
			i++;
		}
		else
		{
			a[q++] = aux[j];
			j++;
		}
	}
	while (i <= m)
		a[q++] = aux[i++];
	while (j <= r)
		a[q++] = aux[j++];
}

/*quicksort*/
void quicksort(int a[], int l, int r)
{
	if (r <= l)
		return;
	int m = partition(a, l, r);
	quicksort(a, l, m-1);
	quicksort(a, m+1, r);
}

int partition(int a[], int l, int r)
{	
	int v = a[l];
	int i = l;
	int j = r;
	while (i < j)
	{
		while (i < j && a[j] >= v)
			j--;
		a[i] = a[j];
		while (i < j && a[i] <= v)
			i++;
		a[j] = a[i];
	}
	a[i] = v;
	
	return i;
}

/*shellsort*/
void shellsort(int a[], int l, int r)
{	
	if (r <= l)
		return;
	int gap = 1;
	while (gap < (r-l+1)/3)
		gap = gap*3+1;
	for (; gap >= 1; gap/=3)
	{
        for (int i = l+gap; i <= r; i++)
        {   
			int j = i;
            while (j >= l+gap && a[j] < a[j-gap])
            {	
				/*swap a[j] and a[j-gap]*/
				int tmp = a[j];
				a[j] = a[j-gap];
				a[j-gap] = tmp;
				j-=gap;
            }
             
        }
	}
}

/*heapsort*/
void heapsort(int a[], int l, int r)
{
	for (int i = r; i >= l; i--)
	{
		adjust(a, l, i);
		int tmp = a[l];
		a[l] = a[i];
		a[i] = tmp;
	}
	
}

void adjust(int a[], int l, int r)
{
	int k = (r-l+1)/2+l-1;
	for (int i = k; i >= l; i--)
	{
		int j = i;
		while (j <= k)
		{	
			if (a[2*j] >= a[2*j+1])
			{
				if (a[2*j] > a[j])
				{	int tmp = a[j];
					a[j] = a[2*j];
					a[2*j] = tmp;
					j = 2*j;
				}
				else
				    break;
			}
			else
			{
				if (a[2*j+1] > a[j])
				{	int tmp = a[j];
					a[j] = a[2*j+1];
					a[2*j+1] = tmp;
					j = 2*j+1;
				}
				else
				    break;
			}
			
		}
	}
}
