# import and output
qname = "C2"
fin = open(qname,'r')
fout = open(qname+"-ans","w")
    #終了条件
n = int(fin.readline())
#    n,m = map(int,fin.readline().split())
#    a = list(map(int,fin.readline().split()))

    #処理
for i in range(n):
    x,y = map(int,fin.readline().split())
    if 0 <= x <= -1*y and y < 0:
        ans = abs(y)
    elif -1*y <= x <= 0 and y > 0:
        ans = abs(y)
    else:
        ans = min(abs(x),abs(x+y))+abs(y)

    #書き込み
    fout.write(str(ans)+"\n")

fin.close()
fout.close()
print("complete")