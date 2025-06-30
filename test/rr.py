import bisect
from collections import deque

MAX_STRIP = 10**15

def main():
    import sys
    data = sys.stdin.read().split()
    t = int(data[0])
    index = 1
    out_lines = []
    for _ in range(t):
        n = int(data[index]); index += 1
        k = int(data[index]); index += 1
        p = list(map(int, data[index:index+n]))
        index += n
        d = list(map(int, data[index:index+n]))
        index += n
        q = int(data[index]); index += 1
        queries = list(map(int, data[index:index+q]))
        index += q
        
        delays_dict = {}
        for i in range(n):
            delays_dict[p[i]] = d[i]
        
        sorted_p = p
        states = []
        for pos in p:
            for direction in [1, -1]:
                for mod_val in range(k):
                    states.append((pos, direction, mod_val))
        
        next_state_map = {}
        res = {state: False for state in states}
        
        for state in states:
            pos, direction, mod_val = state
            if mod_val == delays_dict[pos]:
                new_dir = -direction
            else:
                new_dir = direction
                
            new_pos0 = pos + new_dir
            
            if new_pos0 < 1 or new_pos0 > MAX_STRIP:
                next_state_map[state] = "EXIT"
                continue
                
            if new_dir == 1:
                idx_next = bisect.bisect_left(sorted_p, new_pos0)
                if idx_next < len(sorted_p):
                    next_p = sorted_p[idx_next]
                    distance = next_p - new_pos0
                else:
                    next_state_map[state] = "EXIT"
                    continue
            else:
                idx_next = bisect.bisect_right(sorted_p, new_pos0) - 1
                if idx_next >= 0:
                    next_p = sorted_p[idx_next]
                    distance = new_pos0 - next_p
                else:
                    next_state_map[state] = "EXIT"
                    continue
                    
            total_time = 1 + distance
            mod_next = (mod_val + total_time) % k
            next_state = (next_p, new_dir, mod_next)
            next_state_map[state] = next_state
        
        rev_graph = {}
        queue = deque()
        
        for state in states:
            next_val = next_state_map[state]
            if next_val == "EXIT":
                res[state] = True
                queue.append(state)
            else:
                if next_val not in rev_graph:
                    rev_graph[next_val] = []
                rev_graph[next_val].append(state)
                
        while queue:
            s = queue.popleft()
            if s in rev_graph:
                for t_state in rev_graph[s]:
                    if not res[t_state]:
                        res[t_state] = True
                        queue.append(t_state)
                        
        for a_i in queries:
            idx = bisect.bisect_left(sorted_p, a_i)
            if idx == len(sorted_p):
                out_lines.append("YES")
                continue
                
            p0 = sorted_p[idx]
            if p0 == a_i:
                time0 = 0
            else:
                time0 = p0 - a_i
            mod0 = time0 % k
            state0 = (p0, 1, mod0)
            
            if res.get(state0, False):
                out_lines.append("YES")
            else:
                out_lines.append("NO")
                
    sys.stdout.write("\n".join(out_lines) + "\n")

if __name__ == '__main__':
    main()