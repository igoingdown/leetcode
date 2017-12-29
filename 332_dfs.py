class Solution(object):
    def findItinerary(self, tickets):
        """
        :type tickets: List[List[str]]
        :rtype: List[str]
        """
        d = {}
        visited = [False for _ in range(len(tickets))]
        for i in range(len(tickets)):
            t = tickets[i]
            if t[0] not in d:
                d[t[0]] = []
            d[t[0]].append(i)
        for k in d.keys():
            d[k] = sorted(d[k], key=lambda x: tickets[x][1])
        path = ["JFK"]
        self.dfs(tickets, d, visited, path)
        return path
    
    def dfs(self, tickets, d, visited, path):
        if len(path) == len(tickets) + 1 or path[-1] not in d: return
        for t_index in d[path[-1]]:
            if not visited[t_index]:
                visited[t_index] = True
                path.append(tickets[t_index][1])
                self.dfs(tickets, d, visited, path)
                if len(path) == len(tickets) + 1: return
                del path[-1]
                visited[t_index] = False