class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        obstacles = set(tuple(x) for x in obstacles)
        i = 0
        x,y = 0,0
        max_dist = float('-inf')
        direction = "N"

        while(i<len(commands)):
            if(commands[i]==-1):
                if(direction=='N'):
                    direction = 'E'
                elif(direction=='S'):
                    direction = 'W'
                elif(direction=='W'):
                    direction = 'N'
                else:
                    direction = 'S'
            elif(commands[i]==-2):
                if(direction=='N'):
                    direction = 'W'
                elif(direction=='S'):
                    direction = 'E'
                elif(direction=='W'):
                    direction = 'S'
                else:
                    direction = 'N'
            else:
                if(direction=='N'):
                    while(commands[i]!=0):
                        commands[i] -= 1
                        y += 1
                        if((x,y) in obstacles):
                            y -= 1
                            break
                elif(direction=='E'):
                    while(commands[i]!=0):
                        commands[i] -= 1
                        x += 1
                        if((x,y) in obstacles):
                            x -= 1
                            break
                elif(direction=='W'):
                    while(commands[i]!=0):
                        commands[i] -= 1
                        x -= 1
                        if((x,y) in obstacles):
                            x += 1
                            break
                else:
                    while(commands[i]!=0):
                        commands[i] -= 1
                        y -= 1
                        if((x,y) in obstacles):
                            y += 1
                            break

            if(max_dist<x*x + y*y):
                max_dist = pow(x,2) + pow(y,2)

            i += 1

        return(max_dist)