# import and output
qname = "R"
fin = open(qname,'r')
fout = open(qname+"-ans","w")
while True:
    #終了条件
    n = int(fin.readline())
#    n,m = map(int,fin.readline().split())
#    a = list(map(int,fin.readline().split()))
    if n == 0:
        break

    ans = 0 #答え（初期化）
    #処理

    v = list(map(int,fin.readline().split()))
    for i in range(n-2):
        if v[i] < v[i+1] > v[i+2]:
            ans+=1


    #書き込み
    fout.write(str(ans)+"\n")

fin.close()
fout.close()
print("complete")