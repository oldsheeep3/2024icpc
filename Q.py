# import and output
qname = "Q1"
fin = open(qname,'r')
fout = open(qname+"-ans","w")
while True:
    #終了条件
    n = int(fin.readline())
#    n,m = map(int,fin.readline().split())
#    a = list(map(int,fin.readline().split()))
    if n == 0:
        break
    a = list(map(int,fin.readline().split()))
    sa = pow(10,4)
    ans = 0
    for i in range(n):
        if abs(2023 - a[i]) < sa:
            sa = abs(2023-a[i])
            ans = i + 1
        
    
    #処理


    #書き込み
    fout.write(str(ans)+"\n")

fin.close()
fout.close()
print("complete")