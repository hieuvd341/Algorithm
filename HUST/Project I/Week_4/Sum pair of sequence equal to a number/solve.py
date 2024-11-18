s = input()
arr = s.split(" ")
n = int(arr[0])
M = int(arr[1])
s = input()
arr = s.split(" ")
nums = []
for i in range(0, n):
    nums.append(int(arr[i]))

nums = sorted(nums)

def count_pairs_with_sum(nums, M):
    nums.sort()
    
    left, right = 0, len(nums) - 1
    count = 0
    
    while left < right:
        current_sum = nums[left] + nums[right]
        if current_sum == M:
            count += 1
            left += 1
            right -= 1
        elif current_sum < M:
            left += 1
        else:
            right -= 1
            
    return count

print(count_pairs_with_sum(nums, M))
