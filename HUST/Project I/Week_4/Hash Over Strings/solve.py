s1 = input()
arr = s1.split()
n = int(arr[0])
m = int(arr[1])

def compute_hash(s, m):
    hash_value = 0
    k = len(s)
    for i in range(k):
        hash_value = (hash_value * 256 + ord(s[i])) % m
    return hash_value
hash_codes = []
for _ in range(n):
    string = input().strip()  
    hash_code = compute_hash(string, m)  
    hash_codes.append(hash_code)
for code in hash_codes:
    print(code)
