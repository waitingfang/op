package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func main() {
	ll := ListNode{Val: 1, Next: nil}
	reverseKGroup(&ll, 2)
}

func reverseKGroup(head *ListNode, k int) *ListNode {
	if head == nil || head.Next == nil || k < 2 {
		return head
	}

	p := new(ListNode)
	s := new(ListNode)
	l := k
	p.Next = head
	head = p
	s = p

	for s != nil && k != 0 {
		s = s.Next
		k--
	}

	for s != nil {
		reverse(&p, &s)
		k = l
		for s != nil && k != 0 {
			s = s.Next
			k--
		}
	}
	return head.Next
}

func reverse(p **ListNode, s **ListNode) {
	prev := (*p).Next
	tmp := (*p).Next
	tail := (*p).Next
	flag := (*s).Next

	(*p).Next = nil
	for prev != flag {
		tmp = (*p).Next
		(*p).Next = prev
		prev = prev.Next
		(*p).Next.Next = tmp
	}
	tail.Next = prev
	*p = tail
	*s = tail
}
