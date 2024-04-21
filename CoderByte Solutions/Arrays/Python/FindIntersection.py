def FindIntersection(strArr):
  list1 = [int(num) for num in strArr[0].split(', ')]
  list2 = [int(num) for num in strArr[1].split(', ')]
  intersection = set(list1) & set(list2)
  result = sorted(intersection)
  return ','.join(map(str, result)) if result else "false"

# keep this function call here 
print(FindIntersection(input()))