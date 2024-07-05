# import and output
qname = "S"
fin = open(qname,'r')
fout = open(qname+"-ans","w")
while True:
    #終了条件
    # n = int(fin.readline())
#    n,m = map(int,fin.readline().split())
    A = list(map(int,fin.readline().split()))
    if sum(A) == 0:
        break
    while len(A) > 1:
        A.sort()
        for i in range(len(A)-1):
            A[i+1]-=A[0]
        A=[i for i in A if i != 0]
    
    #処理


    #書き込み
    fout.write(str(A[0])+"\n")

fin.close()
fout.close()
print("complete")