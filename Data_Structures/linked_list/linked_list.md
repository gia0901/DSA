## So sánh Singly và Doubly Linked List

| Feature            | Singly LL        | Doubly LL |
| ------------------ | ---------------- | --------- |
| push_front         | O(1)             | O(1)      |
| pop_front          | O(1)             | O(1)      |
| push_back          | O(1) nếu có tail | O(1)      |
| pop_back           | O(n)             | O(1)      |
| erase current node | khó              | O(1)      |
| reverse traversal  | không            | có        |
| memory overhead    | thấp hơn         | cao hơn   |

## Câu hỏi
Tại sao doubly linked list tốn memory hơn?
-> Mỗi node tốn thêm 1 con trỏ prev.

Tại sao std::list cache locality kém?
    Vì các node nằm rải rác trên heap.
    CPU cache hoạt động tốt nhất khi: dữ liệu nằm liên tiếp trong memory
    Ví dụ std::vector:
    [1][2][3][4]
    => CPU prefetch/cache rất hiệu quả.

Iterator invalidation của list như thế nào?

Tại sao pop_back doubly list là O(1)?

Nếu node bị corrupt prev/next thì hậu quả?

Sentinel node là gì?
    Sentinel node (dummy node):

    node đặc biệt
    không chứa data thực
    dùng để simplify logic
    
Tại sao production code ít dùng linked list?

Vì complexity trên giấy ≠ performance thực tế
Linked list có nhiều vấn đề:
1. Cache locality cực kém

Đây là vấn đề lớn nhất.

2. Memory overhead cao

Mỗi node:

data
next
prev
3. Allocation cost cao

Mỗi insert:

thường cần heap allocation

Heap allocation rất đắt.

4. Fragmentation

Nhiều allocation nhỏ:

memory fragmentation
5. Random access cực tệ
list[i]

không làm được O(1).

Trong thực tế

std::vector thường:

nhanh hơn
đơn giản hơn
cache-friendly hơn

Ngay cả khi:

complexity lý thuyết xấu hơn.
Linked list chỉ thực sự phù hợp khi:
insert/delete giữa container rất nhiều
cần stable iterator/reference
workload đặc thù
Đây là insight rất quan trọng cho Middle+

“Big-O không phải toàn bộ performance.”