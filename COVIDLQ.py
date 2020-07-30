if __name__ == '__main__':
    t = int(input())

    while(t):
	    t-=1
	    a = list(map(int,input().split()))
	    oneindex = []
	    for i in range(0, len(a)):
		    if a[i]==1:
			    oneindex.append(i)

	    mindistance = 1000
	    for i in range(0, len(oneindex)-1):
		    if mindistance<(oneindex[i+1]-oneindex[i]):
			    mindistance = oneindex[i+1]-oneindex[i]

	    if mindistance>=6:
		    print("YES\n")
	    else:
		    print("NO\n")