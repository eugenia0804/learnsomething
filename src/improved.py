def max_area(height):
    max_area = 0
    n = len(height)
    
    left = 0
    right = n-1
    
    while left<right:
        area = min(height[left],height[right])
        max_area = max(max_area, area)
        
        if height[left] > height[right]:
            right -= 1
        else:
            left += 1

    return max_area