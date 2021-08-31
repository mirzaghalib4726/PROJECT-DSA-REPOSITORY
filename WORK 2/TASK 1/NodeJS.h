#pragma once
template <class G>
struct NodeJS
{
	G data;
	NodeJS<G>* next;
};