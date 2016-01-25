int binary_search(const std::vector<int>& vec, int start, int end, const int& key)
{
  // Termination condition: start index greater than end index
  if(start > end)
    {
      return -1;
    }

  // Find the middle element of the vector and use that for
  // splitting the array in two pieces.
  const int middle = start + ((end - start) / 2);

  if(vec[middle] == key)
    {
      return middle;
    }


  else if(vec[middle] > key)
    {
      return binary_search(vec,start,middle - 1, key);
    }

  return binary_search(vec, middle + 1, end, key);

}
