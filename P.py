# import and output
qname = "P"
fin = open(qname,'r')
fout = open(qname+"-ans","w")
while True:
    #終了条件
    n = int(fin.readline())
    if n == 0:
        break
    a = list(map(int,fin.readline().split()))
    

    ans = "" #答え（初期化）
    #処理

    ans = str(max(a))+"\n"

    #書き込み
    fout.write(ans)

fin.close()
fout.close()
print("complete")