// // // 2 downvotes 
// // //Q2
// // #include <bits/stdc++.h>
// // using namespace std;

// // const int mod = 1e9 + 7;

// // vector<vector<int>>dp;

// // int f(int n,int k){
// //     if(n < k) return 0;
// //     if(n == k) return 1;
// //     if(k == 1) return 1;
// //     if(dp[n][k] != -1) return dp[n][k];
// //     return dp[n][k] = ( (k * f(n - 1,k)) % mod + (f(n - 1,k - 1)) % mod ) % mod;
// // }

// // int main() {
// //     int t;
// //     cin>>t;
// //     while(t--){
// //     	int n;
// //     	cin>>n;
// //     	dp.resize(n + 1,vector<int>(n + 1,-1));
// //     	long ans = 0,fac = 1;
// //     	for(int k = 1;k <= n;k++){
// //     	    fac *= k;
// //     	    ans = (ans + (fac * f(n,k)) % mod) % mod;
// //     	}
// //     	cout<<ans<<endl;
// //     }
// // 	return 0;
// // }

// // //GYAN
// // Q1 : Pretty straightforward. If the opponent gets to the "n-3"rd donut, he loses. Do it by hand for a few numbers and you will realise the answer is dependent only on n%3.

// // Q2: So for n people, the number of ranks can be [1,n]. If there is 1 rank, only one way (i.e. everyone gets rank 1). If there are n ranks (1,2,3....,n), there are n! ways, since its just the order of people that matter.

// //   Lets see for a general k (1<=k<=n). This is equivalent to 

// //       (i)  first making k groups out of n distinct people (each group gets one rank) 
// //                        To make k groups of n people, we can either directly Stirling Numbers of the Second Kind, or derive its recurrence relation. Lets S(n,k) be the no. of ways of making k groups out of n distinct people
// //                        To partition n people into k classes, isolate one of them - Mr. X - and do one of two things: put him in a partition of his own (you now have to partition the other n-1 into k−1 classes), or don't put him in a partition of his own; meaning, first partition the other n-1 guys into k classes, and then pick one of the k classes and throw Mr. X in there. The first case gives you S(n-1,k−1) , and the second case gives you k*S(n-1,k).

// //                        => S(n,k) = k*S(n-1,k) + S(n-1,k−1)            (this is called Stirling Numbers of the Second Kind)
                        
// //       (ii) and then distributing k ranks to these k groups. 
// //                         This is just k! ways.

// //   So its equal to k! * S(n,k)
// // Sum k! * S(n-1,k) for all k (from 1 to n) will give you the answer.


// //                                                     gyan 2
// // Q1: If you look at the problem the problem looks very tough.
// // But when you sit back and write down the problem with cases, the following observations were noted:
// // Case 1:When n=1,4,7,10,13,....etc you can do nothing and the player who starts will definitely lose.( Look closely when n%3=1 the player who starts always loses.)
// // Case 2:When n=2,5,8,11,14.....etc you always win no matter what. Basically this reduces the problem to case 1 only thats why the starting player always win.
// // (Again look closely when n%3=2 the player who starts always wins.)
// // Case 3:When n=3,6,9,12,15.....etc you always win no matter what. Basically this case also reduces the problem to case 1 only thats why the starting player always win.
// // (Again look closely when n%3=0 the player who starts always wins.)
// // Insights:::
// // I also solved this problem by breaking them down into cases and then seeing a pattern. This is essentially what we have to do. in the problem, just look for that pattern by finding the solution by taking different values of n.
// // Q2: Again I used the same technique for finding the pattern.
// // Considered the problem for n=1,2,3,4,5 and i notices that a recurrence relation is forming.
// // a(n)=Summation(from i=1 to n)a(n-i).
// // with base case a(0)=1. Q2 did take a lot of time as the patterns were not easily visible.
// // But i can say one thing that these questions were not easy to solve and took a lot of time.
// // Nice problems though. Thanks for posting and keep posting in future as well.


// // python

// q1
// def dount_challenge(num: int) -> bool:                                                   
//     # O(N): DP (dfs + memo)
//     dp = {}
//     def dfs(idx):
//         if idx in dp:
//             return dp[idx]
//         if idx == 1:
//             return False
//         dp[idx] = not dfs(idx-1) or not dfs(idx-2)
//         return dp[idx]
//     return dfs(num)

// def dount_challenge2(num: int) -> bool:
//     # O(1): math
//     return (num-1) % 3 != 0


// q2
// # https://math.stackexchange.com/q/2469684
// # https://stackoverflow.com/a/8035816/2740386
// # f(n,k) = (k+1)(f(n-1,k-1) + f(n-1,k))

// def bell_number(num: int) -> int:
//     # O(N**2): DP (tabulation)
//     dp = [[0] * num for _ in range(num)]
//     dp[0][0] = 1
//     for n in range(1, num):
//         for k in range(num):
//             dp[n][k] = (k+1) * (dp[n-1][k-1] + dp[n-1][k])
//     return sum(dp[-1])
    


// //cpp q2
// #include <iostream>
// int main() {
//     int n = 2000, dp[n+1][n+1]={}, ans[n+1]={}, T, MOD = 1e9+7;
//     dp[0][0]=1;
// 	for(int i=0;i<n;++i)
// 	    for(int j=0;j<=i;++j) 
// 	        (dp[i+1][j]+=j*dp[i][j])%=MOD, dp[i+1][j+1]=(j+1)*dp[i][j], (ans[i+1]+=dp[i][j]*(2*j+1))%=MOD;
// 	for(std::cin >> T; T; T--){
// 	    int N; std::cin >> N;
// 	    std::cout << ans[N] << '\n';
// 	}
// 	return 0;
// }

// //gyan but good ig

// For Q1 :

// Generalized dp for instead of taking coins from 1,2 you can take coins from 1,2,3,...k.

// https://leetcode.com/playground/tQpzH7bw

// dp[n] stores the boolean that at nth coins player who starts first wins or not ( 1 / 0).

// dp[0] = 1;
// dp[1] = 0;
// dp[2],...dp[k-1] = 1 , as you can always take the k -1 coins and other player will left with only 1 coin so you always win.

// for other i [k,...n] dp[i] = 1 if and only if for any dp[j] = 0, where j < i & i -j <= k.

// This will be O(N * K) time complexity,.
// If you see the pattern the first player looses when N % 3 = 1, otherwise the player who starts first wins.O(1) time, O(1) space

// For Q2 :
// https://en.wikipedia.org/wiki/Ordered_Bell_number
// https://oeis.org/A034172

// Let me know if you have queries or found anything wrong in this answers.


// //q1 dp c++
// map<int,bool> r;
// bool dp(int n)
// {
//     if(n==1)
//         return false;
//     if(n==2)
//         return true;
//     else
//     {
//         if(r.count(n))
//             return r[n];
//         else
//             r[n]= !dp(n-1)||!dp(n-2);
//         return r[n];
//     }
// }

// //                       gyan but good again ?

// The first question is a simplified version of https://leetcode.com/problems/stone-game-iii/. Just run minimax DP.
// For the second question, precompute factorials and their inverses in O(N) time so that you could query choose(n, k) in O(1). 
// Here is my DP solution which runs in quadratic time. Should be enough as max n is 2000. No idea if a linear solution exists though.

// // Link : https://leetcode.com/discuss/interview-question/602944/de-shaw-online-coding-test

// #include <iostream>
// #include <vector>

// using namespace std;

// const int MAXN = 2000;
// const int MOD = 1e9 + 7;

// int fac[MAXN + 5], facInv[MAXN + 5];
// int dp[MAXN + 5];
// int largestNSolved;

// int powmod(int a, int b) {
// 	int ans = 1;
// 	for(int bit = 30; bit >= 0; bit--) {
// 		ans = (1LL * ans * ans) % MOD;
// 		if(b & (1 << bit)) {
// 			ans = (1LL * ans * a) % MOD;
// 		}
// 	}
// 	return ans;
// }
 
// int choose(int n, int k){
//     return 1LL * fac[n] * facInv[k] % MOD * facInv[n - k] % MOD;
// }

// int solve(int n) {
// 	if(n <= largestNSolved) return dp[n];
// 	for(int i = largestNSolved + 1; i <= n; i++) {
// 		dp[i] = 0;
// 		for(int c = 1; c <= i; c++) {
// 			// ways represents the number of ways of ranking i students such that c of them are ranked first
//             // without loss of generality, the number of ways of ranking the other i - c students is just dp[i-c] as they are just all the ways of ranking i-c students shifted down by 1
// 			int ways = (1LL * choose(i, c) * dp[i-c]) % MOD;
// 			dp[i] += ways;
// 			if(dp[i] >= MOD) dp[i] -= MOD;
// 		}
// 	}
// 	largestNSolved = n;
// 	return dp[n];
// }

// int main() {
// 	// precompute factorials and inverses
// 	fac[0] = 1;
//     for (int i = 1; i <= MAXN; ++i) {
//         fac[i] = 1LL * fac[i-1] * i % MOD;
// 	}
     
//     // from Fermat's little theorem   
//     facInv[MAXN] = powmod(fac[MAXN], MOD-2);
    
//     for (int i = MAXN-1; i >= 0; --i) {
// 		facInv[i] = 1LL * facInv[i + 1] * (i+1) % MOD;
// 	}
	
// 	largestNSolved = 0;
// 	dp[0] = 1;
	
// 	int t; cin >> t;
// 	while(t--) {
// 		int n; cin >> n;
// 		cout << solve(n) << '\n';
// 	}
// }