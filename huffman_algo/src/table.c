#include "compress.h"

void		build_table(t_huffnode *root, t_huffelem table[], unsigned short code, unsigned short size)
{
	if (root)
	{
       	if (root->left)
			build_table(root->left, table, code << 1, size + 1);
		if (root->right)
			build_table(root->right, table, (code << 0x001) | 0x1, size + 1);
		if (!root->left && !root->right)
		{
 			code = htons(code);
			table[(int)root->sym].code = code;
			table[(int)root->sym].size = size;
		}
	}
}
