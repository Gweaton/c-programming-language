# assumes a sorted array
def binary_search(x, array)
  mid_index = array.length / 2

  if (x < array[mid_index])
    binary_search(x, array.slice(0, mid_index))
  elsif (x > array[mid_index])
    binary_search(x, array.slice(mid_index, array.length - 1))
  else
    return array[mid_index] if x == array[mid_index]
    -1
  end
end

puts binary_search(10, [1,2,3,4,5,6,7,8])
