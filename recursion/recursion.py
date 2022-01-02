import collections as co

def findminmax(S):
  print(S)
  if len(S) == 1:
    return S[0], S[0]

  m, n = findminmax(S[1:])
  if S[0] < m:
    m = S[0]
  if S[0] > n:
    n = S[0]

  return m, n

#print(findminmax([3,4,1,6,9]))

def isUnique(S):
  if len(S) == 1:
    return True

  for c in S[1:]:
    if S[0] == c:
      return False

  return isUnique(S[1:])

#print('unique: {}.'.format(isUnique([1,2,3,4,5,6,7])))

def recurProd(a, b):
  if b == 1:
    return a

  return a + recurProd(a, b - 1)

#print('{} * {} = {}'.format(3, 4, recurProd(3, 4)))

def printRod(A, B, C):
  print('A: ', A)
  print('B: ', B)
  print('C: ', C)
  print()

# move n disks from rod A to C, using B as an aux rod
# args: (n, src, aux, dest)
def towerOfHanoi(n, A, B, C):
  # base case: only one disk on rod A. Just move to rod C
  if n == 1:
    C.append(A.pop())
    #printRod(A, B, C)
    return

  # general case:
  # 1. move the top n - 1 disks from rod A to aux rod (B)
  towerOfHanoi(n - 1, A, C, B)
  # 2. move the bottom disk from A to C
  C.append(A.pop())
  # 3. move the top n - 1 disks from aux rod B to C
  towerOfHanoi(n - 1, B, A, C)

n = 6
A = [6,5,4,3,2,1]
B = []
C = []
#towerOfHanoi(n, A, B, C)
#printRod(A, B, C)

# print all subsets of a set of n elements
# setList S: the input set converted to list to extract elements in order
# h: dict of tuples made by subset
def subsets(S, h):
  if len(S) == 1:
    h[tuple(S)] = 1
    return

  h[tuple(S)] = 1

  for _ in range(len(S)):
    k = S.popleft()
    subsets(S, h)
    S.append(k)

mySet = co.deque(['a', 'b', 'c', 'd'])
myHash = {}
subsets(mySet, myHash)
print(sorted([''.join(k) for k in list(myHash.keys())]))
print([''.join(k) for k in list(myHash.keys())])

# reverse string
def reverse(s):
  if len(s) == 1: return s

  return reverse(s[1:]) + s[0]

#print(reverse('abcdef'))

# test palindrome
def isPalindrome(s):
  if len(s) == 1: return True
  if len(s) == 2:
    if s[0] == s[1]:
      return True
    return False

  return (s[0] == s[-1]) and isPalindrome(s[1:-1])

#print(isPalindrome('racecar'))
#print(isPalindrome('racecara'))

import string
vowel = 'aeiouAEIOU'

def isConso(c):
  return c in string.ascii_letters and c not in vowel

def moreVowels(s):
  if len(s) == 1:
    if s[0] in vowel:
      return 1
    elif isConso(s[0]):
      return -1
    return 0

  if s[0] in vowel:
    return moreVowels(s[1:]) + 1
  elif isConso(s[0]):
    return moreVowels(s[1:]) - 1
  return moreVowels(s[1:])

#print(moreVowels('akaiu 0 t 56'))

# arrange seq such that even nums before odd nums
def _arrangeEO(s):
  #print('_arrangeEO({})'.format(s))
  if len(s) == 1:
    return s

  i = s.popleft()
  print('pop {}'.format(i))
  if (i % 2 == 1):
    newS = _arrangeEO(s)
    newS.append(i)
    return newS

  newS = _arrangeEO(s)
  newS.appendleft(i)
  return newS

def arrangeEvenOdd(s):
  if len(s) <= 1: return s

  myDq = co.deque(s)
  return list(_arrangeEO(myDq))

#print(arrangeEvenOdd([1,2,3,4,5,6,7,8,9]))

from bisect import bisect_left

# return the two indices that sum up to k
sum_i = -1
sum_j = -1
sum_found = False
def findSum(S, k, i):
  global sum_i
  global sum_j
  global sum_found
  if (sum_found == True): return True
  if len(S) <= 1: return sum_found

  target = k - S[0]
  pos = bisect_left(S[1:], target)
  if pos != len(S[1:]) and S[1:][pos] == target:
    sum_i = i
    sum_j = i + pos + 1
    sum_found = True

  return findSum(S[1:], k, i + 1)


if (findSum([1,2,3,4,5,9], 14, 0)):
  print("findSum found: [{}, {}]".format(sum_i, sum_j))
