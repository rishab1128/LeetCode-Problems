from datetime import datetime, timedelta,date
class Solution:
    

   
    
    
    def countDaysTogether(self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str) -> int:
        
        def daterange(date1, date2):
            for n in range(int ((date2 - date1).days)+1):
                yield date1 + timedelta(n)
    
       
        
        aliceLst1 = arriveAlice.split('-')
        aliceLst2 = leaveAlice.split('-')
        
        alice_start_day = int(aliceLst1[1])
        alice_start_month = int(aliceLst1[0])
        alice_start_date = date(2022, alice_start_month, alice_start_day)
        
        
        alice_end_day = int(aliceLst2[1])
        alice_end_month = int(aliceLst2[0])
        alice_end_date = date(2022, alice_end_month, alice_end_day)
        
        # print(alice_start_date)
        # print(alice_end_date)
        
        st1 = set()
        
        for dt in daterange(alice_start_date, alice_end_date):
            st1.add(dt.strftime("%Y-%m-%d"))
            
            
            
        
        bobLst1 = arriveBob.split('-')
        bobLst2 = leaveBob.split('-')
        
        bob_start_day = int(bobLst1[1])
        bob_start_month = int(bobLst1[0])
        bob_start_date = date(2022, bob_start_month, bob_start_day)
        
        
        bob_end_day = int(bobLst2[1])
        bob_end_month = int(bobLst2[0])
        bob_end_date = date(2022, bob_end_month, bob_end_day)
        
        # print(alice_start_date)
        # print(alice_end_date)
        
        st2 = set()
        
        for dt in daterange(bob_start_date, bob_end_date):
            st2.add(dt.strftime("%Y-%m-%d"))
            
        
        st3=set(st1.intersection(st2))
        
        ans = len(st3)
        
        
            
        return ans
    
        
        
        