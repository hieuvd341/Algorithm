import re
def preprocessDate(dates: str):
    ans = []
    month_dict = {'Jan':1,'Feb':2,'Mar':3,'Apr':4,'May':5,'Jun':6,\
                  'Jul':7,'Aug':8,'Sep':9,'Oct':10,'Nov':11,'Dec':12}
    for date in dates:
        day, month, year = date.split(" ")
        year = year.split("\n")[0]
        day = re.search(r'(\d+)',day)[0]
        month = month_dict[month]
        print(f"{year}-{month}-{day}")
        
with open("input.txt", "r" ) as file_in:
    file_in.readline()
    lines = file_in.readlines()
    preprocessDate(lines)