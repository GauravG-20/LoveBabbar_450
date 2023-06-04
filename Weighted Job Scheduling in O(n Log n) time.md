# Weighted Job Scheduling in O(n Log n) time
Given N jobs where every job is represented by following three elements of it.

1. Start Time
2. Finish Time
3. Profit or Value Associated     

---
Link: [Question GFG](https://www.geeksforgeeks.org/weighted-job-scheduling-log-n-time/)

---

Find the maximum profit subset of jobs such that no two jobs in the subset overlap.
Example: 

``` 
Input: Number of Jobs n = 4
       Job Details {Start Time, Finish Time, Profit}
       Job 1:  {1, 2, 50} 
       Job 2:  {3, 5, 20}
       Job 3:  {6, 19, 100}
       Job 4:  {2, 100, 200}
Output: The maximum profit is 250.
```
* We can get the maximum profit by scheduling jobs 1 and 4.
* Note that there is longer schedules possible Jobs 1, 2 and 3 
* but the profit with this schedule is 20+50+100 which is less than 250. 
