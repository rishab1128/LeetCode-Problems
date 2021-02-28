import copy
class Solution:
    def closestCost(self, base, top, t):
        top_combo = {0}
        for x in top:
            top_combo_next = copy.deepcopy(top_combo)
            #print(len(top_combo))
            for y in top_combo:
                top_combo_next.add(y+x)
                top_combo_next.add(y+2*x)
            top_combo = top_combo_next
            # print(len(top_combo))
        
        ans = dif = math.inf
        for x in base:
            for y in top_combo:
                cost = x+y
                cdif = abs(t-cost)
                if cdif < dif:
                    ans, dif = cost, cdif
                elif cdif == dif and cost < ans:
                    ans, dif = cost, cdif
        
        return ans