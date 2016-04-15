// 题目地址：https://leetcode.com/problems/add-two-numbers/
// 题目内容：
// You are given two linked lists representing two non-negative numbers. 
// 
// The digits are stored in reverse order and each of their nodes contain a single digit. 
// 
// Add the two numbers and return it as a linked list.
// 
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// 
// 题目翻译：
// 
// 给定两个链表表示两个非负数。数字逆序存储，每个节点包含一个单一的数字。
// 
// 计算两个数的和，并以链表的形式返还。
// 
// 题目分析：
// 
// 需要考虑进位，当最后一次加完之后，这时链表也都为空时，一定要考虑是否需要进位。
// 
// 有一种算法是先遍历这个链表将数值都加起来，最后在根据这个总和，进行一位位的添加节点的执行效率偏低，
// 
// 要没计算一次就新建一个节点，要注意此节点是否需要进位，当遍历完传入的两个list，最后一次也要考虑进位，
// 
// 新建节点。
// 
// 代码：
// 
// 运行时间为 0ms

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int ix1 = 0;
        int ix2 = 0;
        int iNum = 0;
        int iCarry = 0;
        ListNode *pHand = NULL;
        ListNode *pNow = NULL;
        while((NULL != l1)||(NULL != l2))
        {
            ix1 = getXPostMoveNext(l1);
            ix2 = getXPostMoveNext(l2);
            
            iNum = ix1 + ix2 + iCarry;
            
            ListNode *pNode = new ListNode(iNum%10);
            
            if(NULL ==pHand)
            {//第一次把新建节点赋值给头指针和当前指针
                pHand = pNode;
                pNow = pNode;
            }
            else
            {//随后只对当前节点操作
                pNow->next = pNode;
                pNow = pNode;
            }
            
            iCarry = iNum/10;
        }
        
        if(iCarry > 0)
        {
           ListNode *pNode = new ListNode(iCarry%10); 
           pNow->next = pNode;
           pNow = pNode;
        }
        
        return pHand;
        
    }
private:
    int getXPostMoveNext(ListNode*&L)
    {
        int x = 0;
        if(NULL != L)
        {
            x = L->val;
            L = L->next;
        }
        
        return x;
    }
};

/*对于上面的指针操作处可以做如下优化，此处的优化只是编程技巧的优化，对于效率而言没有提升：*/

ListNode *pHand=NULL;

ListNode**pMove=&pHand;

while(NULL != L1 || NULL != L2)

{

    ListNode * pNode = new ListNode(iNum%10);

    *PMove = pNode;//用这两行代码可以对上述的if判断（是否是第一次创建几点）进行替换，可以使代码更精炼

    pMove = &(pNode->next)

}