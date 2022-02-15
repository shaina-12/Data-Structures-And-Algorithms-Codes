#User function Template for python3

# design the class in the most optimal way
class DLLNode:
    def __init__(self, key, val):
        self.val = val
        self.key = key
        self.prev = None
        self.next = None

class LRUCache:
      
    #Constructor for initializing the cache capacity with the given value.  
    def __init__(self,cap):
        #code here
        self.capacity = cap
        self.map = {}
        self.head = DLLNode(0,0)
        self.tail = DLLNode(0,0)
        self.head.next = self.tail
        self.tail.prev = self.head
        self.count = 0
    def deleteHead(self,node):
        node.prev.next = node.next
        node.next.prev = node.prev
    def addToHead(self,node):
        node.next = self.head.next
        node.next.prev = node
        node.prev = self.head
        self.head.next = node
    #Function to return value corresponding to the key.
    def get(self, key):
        #code here
        if(key in self.map):
            node = self.map[key]
            result = node.val
            self.deleteHead(node)
            self.addToHead(node)
            return result
        else:
            return -1
        """
        if(self.lru.get(key)==None):
            return -1
        else:
            return self.lru.get(key)
        """
    #Function for storing key-value pair.   
    def set(self, key, value):
        #code here
        if(key in self.map):
            node = self.map[key]
            node.val = value
            self.deleteHead(node)
            self.addToHead(node)
        else:
            node = DLLNode(key,value)
            self.map[key] = node
            if(self.count<self.capacity):
                self.count += 1
                self.addToHead(node)
            else:
                del self.map[self.tail.prev.key]
                self.deleteHead(self.tail.prev)
                self.addToHead(node)
        """
        if(self.size<self.cap):
            self.lru[key]=  value
            self.stack.append((key,value))
            self.size += 1
        else:
            a = self.stack[0][0]
            self.stack.pop(0)
            self.lru.pop(a)
            self.size -= 1
            self.lru[key] = value
            self.stack.append((key,value))
            self.size += 1
        """

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        cap = int(input())  # capacity of the cache
        qry=int(input())  #number of queries
        a = list(map(str, input().strip().split()))  # parent child info in list
        
        lru=LRUCache(cap)
        
       
        i=0
        q=1
        while q<=qry:
            qtyp=a[i]
            
            if qtyp=='SET':
                lru.set(int(a[i+1]),int(a[i+2]))
                i+=3
            elif qtyp=='GET':
                print(lru.get(int(a[i+1])),end=' ')
                i+=2
            q+=1
        print()
# } Driver Code Ends
