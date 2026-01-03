class Solution(object):
    def areSentencesSimilar(self, words1, words2, pairs):
        """
        :type words1: List[str]
        :type words2: List[str]
        :type pairs: List[List[str]]
        :rtype: bool
        """
        if len(words1) != len(words2): return False
        d = {}
        for p in pairs:
            if p[0] not in d:
                d[p[0]] = set()
            if p[1] not in d:
                d[p[1]] = set()
            d[p[0]].add(p[1])
            d[p[1]].add(p[0])
        for w in words1:
            if w not in d:
                d[w] = set()
            d[w].add(w)
        for w in words2:
            if w not in d:
                d[w] = set()
            d[w].add(w)
        for i in range(len(words1)):
            if words2[i] not in d[words1[i]]:
                return False
        return True
