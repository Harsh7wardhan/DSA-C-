void Heapify(vector<int> &arr, int size, int index)
{

    // for min heap

    int smallest = index;

    int left = 2 * index + 1; // for zero page indexing

    int right = 2 * index + 2;

    // just using heapify algorithm

    if (left < size && arr[smallest] > arr[left])
    {

        smallest = left;
    }

    if (right < size && arr[smallest] > arr[right])
    {

        smallest = right;
    }

    if (smallest != index)
    {

        swap(arr[smallest], arr[index]);

        Heapify(arr, size, smallest);
    }
}

vector<int> buildMinHeap(vector<int> &arr)

{

    for (int i = (arr.size() / 2) - 1; i >= 0; i--)
    {

        Heapify(arr, arr.size(), i);
    }

    return arr;
}