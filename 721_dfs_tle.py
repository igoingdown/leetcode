class Solution(object):
    def accountsMerge(self, accounts):
        """
        :type accounts: List[List[str]]
        :rtype: List[List[str]]
        """
        accounts = sorted(accounts, key=lambda account: account[0])
        visited = [-1 for _ in range(len(accounts))]
        for i in range(len(accounts)):
            self.dfs(accounts, visited, i, i)
        for i in range(len(accounts)):
            s = set(accounts[i][1:]) | set(accounts[visited[i]][1:])
            l = [accounts[i][0]]
            for str in list(s):
                l.append(str)
            accounts[visited[i]] = l
            if i != visited[i]: accounts[i] = [accounts[i][0]]
        res = []
        for i in range(len(accounts)):
            if len(accounts[i]) > 1:
                res.append(sorted(accounts[i]))
        return res
    
    def dfs(self, accounts, visited, start, id):
        if visited[start] >= 0: return
        visited[start] = id
        for i in range(0, len(accounts)):
            if accounts[start][0] != accounts[i][0] or i == start: continue
            s = set(accounts[start][1:]) & set(accounts[i][1:])
            if len(s) > 0:
                self.dfs(accounts, visited, i, id)