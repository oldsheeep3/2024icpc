# import and output
qname = "D"
fin = open(qname,'r')
fout = open(qname+"-ans","w")
while True:
    #終了条件
    n = int(fin.readline())
#    n,m = map(int,fin.readline().split())
#    a = list(map(int,fin.readline().split()))
    if n == 0:
        break

    ans = 0
    XY = []
    dx =1
    dy = 0
    ab = list(map(int,fin.readline().split()))
    #処理
    for i in range(n):
        XY.append(list(map(int,fin.readline().split())))
    while ab[2] > 1:
        for i in range(len(XY)):
            if XY[i]==ab:
                ab[0]+=dx*(-1)
                ab[1]+=dy*(-1)
                if dx == 1:
                    dx = 0
                    dy = 1
                elif dx == -1:
                    dx = 0
                    dy = -1
                elif dy == 1:
                    dx = -1
                    dy = 0
                else:
                    dx = 1
                    dy = 0
            else:
                ab[0]+=dx
                ab[1]+=dy
                ab[2]-=1
    
    #書き込み
    fout.write(str(ab[2])+"\n")

fin.close()
fout.close()
print("complete")