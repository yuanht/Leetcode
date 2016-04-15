// ��Ŀ��ַ��https://leetcode.com/problems/add-two-numbers/
// ��Ŀ���ݣ�
// You are given two linked lists representing two non-negative numbers. 
// 
// The digits are stored in reverse order and each of their nodes contain a single digit. 
// 
// Add the two numbers and return it as a linked list.
// 
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// 
// ��Ŀ���룺
// 
// �������������ʾ�����Ǹ�������������洢��ÿ���ڵ����һ����һ�����֡�
// 
// �����������ĺͣ������������ʽ������
// 
// ��Ŀ������
// 
// ��Ҫ���ǽ�λ�������һ�μ���֮����ʱ����Ҳ��Ϊ��ʱ��һ��Ҫ�����Ƿ���Ҫ��λ��
// 
// ��һ���㷨���ȱ������������ֵ��������������ڸ�������ܺͣ�����һλλ����ӽڵ��ִ��Ч��ƫ�ͣ�
// 
// Ҫû����һ�ξ��½�һ���ڵ㣬Ҫע��˽ڵ��Ƿ���Ҫ��λ���������괫�������list�����һ��ҲҪ���ǽ�λ��
// 
// �½��ڵ㡣
// 
// ���룺
// 
// ����ʱ��Ϊ 0ms

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
            {//��һ�ΰ��½��ڵ㸳ֵ��ͷָ��͵�ǰָ��
                pHand = pNode;
                pNow = pNode;
            }
            else
            {//���ֻ�Ե�ǰ�ڵ����
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

/*���������ָ������������������Ż����˴����Ż�ֻ�Ǳ�̼��ɵ��Ż�������Ч�ʶ���û��������*/

ListNode *pHand=NULL;

ListNode**pMove=&pHand;

while(NULL != L1 || NULL != L2)

{

    ListNode * pNode = new ListNode(iNum%10);

    *PMove = pNode;//�������д�����Զ�������if�жϣ��Ƿ��ǵ�һ�δ������㣩�����滻������ʹ���������

    pMove = &(pNode->next)

}