# import and output
qname = "B"
fin = open(qname,'r')
fout = open(qname+"-ans","w")
while True:
    #終了条件
    n = int(fin.readline())
#    n,m = map(int,fin.readline().split())
#    a = list(map(int,fin.readline().split()))
    if n == 0:
        break

    ans = "" #答え（初期化）
    #処理


    #書き込み
    fout.write(ans)

fin.close()
fout.close()
print("complete")