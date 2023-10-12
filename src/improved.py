def max_area(height):
    max_area = 0
    left = 0
    right = 0

    while left < right:
        area = min(height[left], height[right]) * (right - left)
        max_area = max(area, max_area)
        if height[left] > height[right]:
            right -= 1
        else:
            left += 1

    return max_area