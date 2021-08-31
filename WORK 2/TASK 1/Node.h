#pragma once
template <class G>
struct Node
{
	G data;
	Node<G>* next;
};