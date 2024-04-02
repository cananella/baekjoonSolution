
t=int(input())
for _ in range(t):
    n=int(input())
    dp=[[0 for _ in range(2)] for _ in range(n+1)]
    sticker=[list(map(int,input().split())) for _ in range(2)]
    for i in range(n):
        if i<2:
            dp[i+1][0]= dp[i][1]+sticker[0][i]
            dp[i+1][1]= dp[i][0]+sticker[1][i]
        else:
            dp[i+1][0]=max(dp[i][1]+sticker[0][i], max(dp[i-1][0], dp[i-1][1])+sticker[0][i])
            dp[i+1][1]=max(dp[i][0]+sticker[1][i], max(dp[i-1][0], dp[i-1][1])+sticker[1][i])

    # for i in range(2):
    #     for j in range(n+1):
    #         print(dp[j][i],end=" ")
    #     print("")

    print(max(dp[-1][0],dp[-1][1]))
    
