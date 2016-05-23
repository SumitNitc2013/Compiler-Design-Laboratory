idlist* make_id_node(char* NAME,int size,tnode* node)
{
	//printf("in make_id_node\n");
	idlist* temp;
	temp=(idlist*)malloc(sizeof(idlist));
	temp->NAME=(char*)malloc(50*sizeof(char));
	strcpy(temp->NAME,NAME);
	temp->size=size;
	temp->idPtr=node;
	temp->next=NULL;
	//printf("out make_id_node\n");
	return temp;
}

void insert_id(idlist* node)
{
	//printf("in insert_id\n");
	if(id_tail==NULL && id_head==NULL)
	{
		id_head=node;
		id_tail=node;
	}

	else
	{
		id_tail->next=node;
		id_tail=node;
	}
	//printf("out insert_id\n");
}

gsymbol* lookup(char* NAME)
{
	gsymbol* temp=head;
	while(temp!=NULL)
	{
		if(strcmp(temp->NAME,NAME)==0)
			return temp;
		temp=temp->NEXT;
	}
	return NULL;	
}


void install(gsymbol* node)
{
	//printf("in install\n");
	node->NEXT=head;
	head=node;
	//printf("out install\n");
}


gsymbol* make_gsymbol_node(char* NAME, int type, int size,tnode* node)
{
	//printf("in make_gsymbol_node\n");
	//printf("creating g node: %s %d\n",NAME,type);
	gsymbol* temp;
	temp=(gsymbol*)malloc(sizeof(gsymbol));
	temp->NAME=(char*)malloc(50*sizeof(char));
	strcpy(temp->NAME,NAME);
	temp->TYPE=type;
	temp->SIZE=size;
	temp->nod=node;
	temp->nod->TYPE=type;
	temp->nod->Gentry=temp;
	temp->NEXT=NULL;
	temp->BINDING=indxe+1;
	indxe=indxe+size;
	return temp;
	//printf("out make_gsymbol_node\n");
}

tnode* makeNumLeafNode(int n)
{
	//printf("jha ji\n");
	tnode* leaf;
	leaf=(tnode*)malloc(sizeof(tnode));
	leaf->TYPE=1;
	leaf->NODETYPE=0;
	leaf->val=n;
	leaf->NAME=(char*)malloc(10*sizeof(char));
	strcpy(leaf->NAME,"CONSTANT");
	leaf->left=NULL;
	leaf->mid=NULL;
	leaf->right=NULL;
	return leaf;
}

tnode* makeVarLeafNode(char* var)
{
	//printf("in var leaf node\n");
	tnode* leaf;
	leaf=(tnode*)malloc(sizeof(tnode));
	//gsymbol *temp;
	//temp=lookup(var);
	//if(temp!=NULL)
	//{
	//	leaf->TYPE=temp->TYPE;
	//	leaf->Gentry=temp;
	//}
	leaf->NODETYPE=1;
	leaf->NAME=(char*)malloc(50*sizeof(char));
	strcpy(leaf->NAME,var);
	leaf->left=NULL;
	leaf->mid=NULL;
	leaf->right=NULL;
	//printf("out var leaf node\n");
	return leaf;
}

tnode* makeNameNode(char c[],tnode* left,tnode* mid,tnode* right)
{
	tnode* name_node;
	name_node=(tnode*)malloc(sizeof(tnode));
	switch(c[0])
	{
		case '+':
			if(left->TYPE!=1 || right->TYPE!=1)
			{
				printf("Compilation Error!!!! TYPE missmatch\n");
				exit(0);
			}
			name_node->TYPE=1;
			name_node->NODETYPE=2;
			name_node->NAME=(char*)malloc(10*sizeof(char));
			strcpy(name_node->NAME,c);
			name_node->left=left;
			name_node->mid=mid;
			name_node->right=right;
			break;

		case '-':
			if(left->TYPE!=1 || right->TYPE!=1)
			{
				printf("Compilation Error!!!!TYPE missmatch\n");
				exit(0);
			}
			name_node->TYPE=1;
			name_node->NODETYPE=2;
			name_node->NAME=(char*)malloc(10*sizeof(char));
			strcpy(name_node->NAME,c);
			name_node->left=left;
			name_node->mid=mid;
			name_node->right=right;
			break;

		case '*':
			if(left->TYPE!=1 || right->TYPE!=1)
			{
				printf("Compilation Error!!!! TYPE missmatch\n");
				exit(0);
			}
			name_node->TYPE=1;
			name_node->NODETYPE=2;
			name_node->NAME=(char*)malloc(10*sizeof(char));
			strcpy(name_node->NAME,c);
			name_node->left=left;
			name_node->mid=mid;
			name_node->right=right;
			break;


		case '/':
			if(left->TYPE!=1 || right->TYPE!=1)
			{
				printf("Compilation Error!!!! TYPE missmatch\n");
				exit(0);
			}
			name_node->TYPE=1;
			name_node->NODETYPE=2;
			name_node->NAME=(char*)malloc(10*sizeof(char));
			strcpy(name_node->NAME,c);
			name_node->left=left;
			name_node->mid=mid;
			name_node->right=right;
			break;


		case '^':
			if(left->TYPE!=1 || right->TYPE!=1)
			{
				printf("Compilation Error!!!! TYPE missmatch\n");
				exit(0);
			}
			name_node->TYPE=1;
			name_node->NODETYPE=2;
			name_node->NAME=(char*)malloc(10*sizeof(char));
			strcpy(name_node->NAME,c);
			name_node->left=left;
			name_node->mid=mid;
			name_node->right=right;
			break;


		case '<':
			if(left->TYPE!=1 || right->TYPE!=1)
			{
				printf("Compilation Error!!!! TYPE missmatch\n");
				exit(0);
			}
			name_node->TYPE=0;
			name_node->NODETYPE=2;
			name_node->NAME=(char*)malloc(10*sizeof(char));
			strcpy(name_node->NAME,c);
			name_node->left=left;
			name_node->mid=mid;
			name_node->right=right;
			break;


		case '>':
			if(left->TYPE!=1 || right->TYPE!=1)
			{
				printf("Compilation Error!!!! TYPE missmatch\n");
				exit(0);
			}
			name_node->TYPE=0;
			name_node->NODETYPE=2;
			name_node->NAME=(char*)malloc(10*sizeof(char));
			strcpy(name_node->NAME,c);
			name_node->left=left;
			name_node->mid=mid;
			name_node->right=right;
			break;



		case '#':
			if(left->TYPE!=1 || right->TYPE!=1)
			{
				printf("Compilation Error!!!! TYPE missmatch\n");
				exit(0);
			}
			name_node->TYPE=0;
			name_node->NODETYPE=2;
			name_node->NAME=(char*)malloc(10*sizeof(char));
			strcpy(name_node->NAME,c);
			name_node->left=left;
			name_node->mid=mid;
			name_node->right=right;
			break;


		case '$':
				if(right->TYPE!=1)
			{
				printf("Compilation Error!!!! TYPE missmatch\n");
				exit(0);
			}
			name_node->NODETYPE=2;
			name_node->TYPE=left->TYPE;
			name_node->NAME=(char*)malloc(10*sizeof(char));
			strcpy(name_node->NAME,c);
			name_node->left=left;
			name_node->mid=mid;
			name_node->right=right;
			break;

		default:
				break;
	}

	if(strcmp(c,"=")==0)
	{
		//printf("in making name_node\n");
		//printf("type left: %d\n",left->TYPE);
		//printf("type right:%d\n",right->TYPE);
		 if(left->TYPE!=right->TYPE)
			{
				printf("Compilation Error!!!! TYPE missmatch\n");
				exit(0);
			}

		else
		{
				if(mid==NULL)
				{
					name_node->TYPE=2;
					name_node->NODETYPE=2;
					name_node->NAME=(char*)malloc(10*sizeof(char));
					strcpy(name_node->NAME,c);
					name_node->left=left;
					name_node->mid=mid;
					name_node->right=right;
				
			//printf("out name_node\n");
				}
		 	   else
				{
					name_node->TYPE=2;
					name_node->NODETYPE=2;
					name_node->NAME=(char*)malloc(10*sizeof(char));
					strcpy(name_node->NAME,c);
					char m[10];
					strcpy(m,"$");
					name_node->left=makeNameNode(m,left,NULL,mid);
					name_node->mid=NULL;
					name_node->right=right;
				//printf("out name_node\n");
				}
		}
		
	}

	else if(strcmp(c,"READ")==0)
	{

		if(left->TYPE!=1)
		{
			printf("Compilation Error!!!! TYPE missmatch\n");
			exit(0);
		}
		else
		{
			if(mid==NULL)
			{
				name_node->TYPE=2;
				name_node->NODETYPE=2;
				name_node->NAME=(char*)malloc(10*sizeof(char));
				strcpy(name_node->NAME,c);
				name_node->left=left;
				name_node->mid=mid;
				name_node->right=right;
			}
			else
			{
				name_node->TYPE=2;
				name_node->NODETYPE=2;
				name_node->NAME=(char*)malloc(10*sizeof(char));
				strcpy(name_node->NAME,c);
				char m[10];
				strcpy(m,"$");
				name_node->left=makeNameNode(m,left,NULL,mid);
				name_node->mid=NULL;
				name_node->right=right;
			}
		}
		
	}

	else if(strcmp(c,"WRITE")==0)
	{
		//printf("in WRITE node\n");
		
		if(left->TYPE!=1)
			{
				printf("Compilation Error!!!! TYPE missmatch\n");
				exit(0);
			}
		else
			{
				name_node->TYPE=2;
				name_node->NODETYPE=2;
				name_node->NAME=(char*)malloc(10*sizeof(char));
				strcpy(name_node->NAME,c);
				name_node->left=left;
				name_node->mid=mid;
				name_node->right=right;
			}
		
		//printf("out WRITE node\n");
	}

	else if(strcmp(c,"IF")==0)
	{
		if(left->TYPE!=0)
		{
			printf("Compilation Error!!!! TYPE missmatch\n");
			exit(0);
		}
		name_node->TYPE=2;
		name_node->NODETYPE=2;
		name_node->NAME=(char*)malloc(10*sizeof(char));
		strcpy(name_node->NAME,c);
		name_node->left=left;
		name_node->mid=mid;
		name_node->right=right;
	}

	else if(strcmp(c,"WHILE")==0)
	{
		if(left->TYPE!=0)
		{
			printf("Compilation Error!!!! TYPE missmatch\n");
			exit(0);
		}
		name_node->TYPE=2;
		name_node->NODETYPE=2;
		name_node->NAME=(char*)malloc(10*sizeof(char));
		strcpy(name_node->NAME,c);
		name_node->left=left;
		name_node->mid=mid;
		name_node->right=right;
	}

	else if(strcmp(c,"dummy")==0)
	{
		name_node->TYPE=2;
		name_node->NODETYPE=2;
		name_node->NAME=(char*)malloc(10*sizeof(char));
		strcpy(name_node->NAME,c);
		name_node->left=left;
		name_node->mid=mid;
		name_node->right=right;
	}

	else if(strcmp(c,"INT")==0)
	{
		//printf("in INT\n");
		name_node->TYPE=1;
		name_node->NODETYPE=2;
		name_node->NAME=(char*)malloc(10*sizeof(char));
		strcpy(name_node->NAME,c);
		name_node->left=left;
		name_node->mid=mid;
		name_node->right=right;
		//printf("out INT\n");
	}

	else if(strcmp(c,"BOOL")==0)
	{
		name_node->TYPE=0;
		name_node->NODETYPE=2;
		name_node->NAME=(char*)malloc(10*sizeof(char));
		strcpy(name_node->NAME,c);
		name_node->left=left;
		name_node->mid=mid;
		name_node->right=right;
	}

	return name_node;
}

int evaluate(tnode* r)
{
	if(r==NULL)
	{
		return 0;
	}

	else if(r->NODETYPE==0)
		return r->val;

	else if(r->NODETYPE==1 && r->left==NULL)
	{

		/*if(lookup(r->NAME)==NULL)
		{
			printf("Error!!!Variable %s not declared\n",r->NAME);
			exit(0);
		}*/
		return array[r->Gentry->BINDING];
	}

	else      //means we are sure that NODETYPE is 2 at this point
	{
		if(strcmp(r->NAME,"+")==0)
		{
			return evaluate(r->left)+evaluate(r->right);
		}

		else if(strcmp(r->NAME,"-")==0)
		{
			return evaluate(r->left)- evaluate(r->right);
		}

		else if(strcmp(r->NAME,"*")==0)
		{
			return evaluate(r->left) * evaluate(r->right);
		}

		else if(strcmp(r->NAME,"/")==0)
		{
			return evaluate(r->left) / evaluate(r->right);
		}

		else if(strcmp(r->NAME,"^")==0)
		{
			return pow(evaluate(r->left),evaluate(r->right));
		}

		else if(strcmp(r->NAME,"<")==0)
		{
			return evaluate(r->left) < evaluate(r->right);
		}

		else if(strcmp(r->NAME,">")==0)
		{
			return evaluate(r->left) > evaluate(r->right);
		}

		else if(strcmp(r->NAME,"#")==0)
		{
			return evaluate(r->left) == evaluate(r->right);
		
		}

		else if(strcmp(r->NAME,"$")==0)
		{	/*
			if(lookup(r->left->NAME)==NULL)
			{
				printf("Error!!!Variable %s not declared\n",r->left->NAME);
				exit(0);
			}*/
			return array[r->left->Gentry->BINDING + evaluate(r->right)];
		}

		else if(strcmp(r->NAME,"=")==0)
		{
			//printf("evaluating = node\n");
			if(strcmp(r->left->NAME,"$")==0)
			{
				/*if(lookup(r->left->left->NAME)==NULL)
				{
					printf("Error!!!Variable %s not declared\n",r->left->left->NAME);
					exit(0);
				}*/
				array[r->left->left->Gentry->BINDING + evaluate(r->left->right)]=evaluate(r->right);
			}
			else
			{
				/*if(lookup(r->left->NAME)==NULL)
				{
					printf("Error!!!Variable %s not declared\n",r->left->NAME);
					exit(0);
				}*/
	
				array[r->left->Gentry->BINDING]=evaluate(r->right);
			}
			//printf("evaluating = node is done\n");
			return 0;
		
		}


		else if(strcmp(r->NAME,"READ")==0)
		{
			int x;
			scanf("%d",&x);
			if(strcmp(r->left->NAME,"$")==0)
			{
				/*if(lookup(r->left->left->NAME)==NULL)
				{
					printf("Error!!!Variable %s not declared\n",r->left->left->NAME);
					exit(0);
				}*/
				array[r->left->left->Gentry->BINDING + evaluate(r->left->right)]=x;
			}

			else
			{
				/*if(lookup(r->left->NAME)==NULL)
				{
					printf("Error!!!Variable %s not declared\n",r->left->NAME);
					exit(0);
				}*/
				array[r->left->Gentry->BINDING]=x;
			}
			return 0;
			
		}


		else if(strcmp(r->NAME,"WRITE")==0)
		{
			//printf("evaluating WRITE node begins\n");
			//printf("BINDING is %d\n",r->Gentry->BINDING);
			//printf("in wr %d\n",array[indxe]);
			//printf("in WRITE %d\n",array[r->Gentry->BINDING]);
			int ans=evaluate(r->left);
			printf("%d\n",ans);
			//printf("evaluating WRITE node done\n");
			return 0;
			
		}


		else if(strcmp(r->NAME,"IF")==0)
		{
			if(r->mid==NULL)
			{
				if(evaluate(r->left)==1)
					evaluate(r->right);
			}
		
			else
			{
				if(evaluate(r->left)==1)
					evaluate(r->mid);
				else
					evaluate(r->right);
			}
			return 0;
		
		}


		else if(strcmp(r->NAME,"WHILE")==0)
		{
			while(evaluate(r->left)==1)
					evaluate(r->right);
			return 0;
		
		}

		else if(strcmp(r->NAME,"dummy")==0)
		{
			//printf("evaluate both left and right\n");
			evaluate(r->left);
			evaluate(r->right);
			//printf("dummy evaluation done\n");
			return 0;
		}
			
	}
}
