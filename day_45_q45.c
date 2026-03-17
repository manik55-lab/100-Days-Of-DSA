class Node:
def __init__(self, val):
    self.val = val
    self.left = None
    self.right = None

# Function to build tree from level order
def build_tree(arr):
if not arr or arr[0] == -1:
    return None

root = Node(arr[0])
queue = [root]
i = 1

while queue and i < len(arr):
    current = queue.pop(0)

    # Left child
    if arr[i] != -1:
        current.left = Node(arr[i])
        queue.append(current.left)
    i += 1

    if i >= len(arr):
        break

    # Right child
    if arr[i] != -1:
        current.right = Node(arr[i])
        queue.append(current.right)
    i += 1

return root

# Function to find height
def height(root):
if root is None:
    return 0
return 1 + max(height(root.left), height(root.right))

# Input
n = int(input())
arr = list(map(int, input().split()))

root = build_tree(arr)
print(height(root))