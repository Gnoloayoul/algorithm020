//binary search
int binarySearch(int *a, int s, int t, int key)
{
	while (s <= t) {
		int mid = s + ((t - s) >> 1);
		if (a[mid] == key)
			return mid;
		if (a[mid] > key)
			t = mid - 1;
		else
			s = mid + 1;
	}
	return -1;
}
int search(int *a, int n, int key)
{
	int s = 0, t = n - 1;
	while (s <= t) {
		if (a[s] < a[t])
			return binarySearch(a, s, t, key); // ordered, use binarySearch
		int mid = s + ((t - s) >> 1);
		//printf("s = %d, t = %d, mid = %d\n", s, t, mid);
		if (a[mid] == key)
			return mid;
		if (a[mid] < a[t]) {
			if (a[mid] < key && key <= a[t]) // right part is ordered
				return binarySearch(a, mid + 1, t, key); //key beteen a[mid] and a[t]
			else
				t = mid - 1;
		} else { // a[mid] > a[t], left part is ordered
			if (a[s] <= key && key < a[mid]) // key between a[s] and a[mid]
				return binarySearch(a, s, mid - 1, key);
			else
				s = mid + 1;
		}
	}
	return -1;
}