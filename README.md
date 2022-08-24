# Incremental Convexhull

### Algorithm CONVEXHULL(P)

***Input.*** A set $P$ of points in the plane.

***Output.*** A list containing the vertices of *CH*(**P**) in clockwise order.

>1.  Sort the points by x-coordinate, resulting in a sequence $p_1, . . . , p_n$.
>2.  Put the points $p_1$ and $p_2$ in a list $L_{upper}$, with $p_1$ as the first point.
>>3.  **for** $i$← 3 **to** $n$
>>>4.  **do** Append $p_i$ to $L_{upper}$.
>>>>5.  **while** $L_{upper}$ contains more than two points and the last three points in $L_{upper}$ do not make a right turn
>>>>>6.  **do** Delete the middle of the last three points from $L_{upper}$.
>7. Put the points $p_n$ and $p_{n−1}$ in a list $L_{lower}$, with $p_n$ as the first point
>8. **for** $i$ ← $n−2$ **downto** 1
>>9. **do** Append $p_i$ to $L_{lower}$.
>>>10. **while** $L_{lower}$ contains more than 2 points and the last three points in $L_{lower}$ do not make a right turn
>>>>11. **do** Delete the middle of the last three points from $L_{lower}$.
>12. Remove the first and the last point from $L{lower}$ to avoid duplication of the points where the upper and lower hull meet.
>13. Append $L_{lower}$ to $L_{upper}$, and call the resulting list $L$.
>14. **return** $L$
