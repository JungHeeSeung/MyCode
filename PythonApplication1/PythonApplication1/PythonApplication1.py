import copy

def isSorted(lst):
    temp = copy.deepcopy(lst)
    temp.sort()
    for i in range(0, len(lst)):
        if temp[i] != lst[i]:
            print("리스트는 정렬되어 있지 않습니다.")
            break
        elif (i+1) == len(lst):
            print("리스트는 정렬되어 있습니다.")


s = input("리스트를 입력하세요:")
lst = s.split()
lst = [eval(i) for i in lst]

isSorted(lst)