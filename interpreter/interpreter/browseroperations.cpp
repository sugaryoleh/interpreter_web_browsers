#include "browseroperations.h" 

class WebTreePatterns
{
public:
	static bool compareForRun(Node*);
	static bool compareForQuit(Node*);
	static bool compareForOpen(Node*);
	static bool compareForClick_Clear(Node*);
	static bool compareForInput(Node*);
	
};

bool WebTreePatterns::compareForRun(Node* head)
{
	if (head->leftChild != nullptr) { throw Exception("left value '" + head->leftChild->token.value + "' is not allowed"); return 0; }
	if (head->rightChild->token.type != Lib::TYPES::RESERVED &&
		( head->rightChild->token.value != "chrome" || head->rightChild->token.value != "edge")) {  throw Exception("right value must has type '" + Lib::TYPES::RESERVED + "', not '" + head->rightChild->token.type + "'"); return 0;}
	if (head->rightChild->rightChild != nullptr || head->rightChild->leftChild != nullptr) { throw Exception("to much params"); return 0; }
	return 1;
}

bool WebTreePatterns::compareForQuit(Node* head)
{
	if (head->rightChild != nullptr) { throw Exception("left value '" + head->leftChild->token.value + "' is not allowed"); return 0; }
	if (head->leftChild->token.type != Lib::TYPES::ID) {
		throw Exception("right value must has type '" + Lib::TYPES::ID + "', not '" + head->leftChild->token.type + "'"); return 0;
	}
	if (head->leftChild->leftChild != nullptr || head->leftChild->leftChild != nullptr) { throw Exception("to much params"); return 0; }
	return 1;
}

bool WebTreePatterns::compareForOpen(Node* head)
{
	VarDictionary* vd = VarDictionary::getVarDict();
	if (head->leftChild == nullptr) { throw Exception("left value for '" + head->leftChild->token.value + "' is abscent"); return 0; }
	if (head->rightChild == nullptr) { throw Exception("right value for '" + head->rightChild->token.value + "' is abscent"); return 0; }
	Token tok = head->leftChild->token;
	if (head->leftChild->token.type != Lib::TYPES::ID) { throw Exception("left value must have  '" + Lib::TYPES::ID+ "'type, not '" + head->leftChild->token.type + "'"); return 0; }
	tok = vd->get(head->leftChild->token.value);
	if (tok.type != Lib::TYPES::BROWSER) { throw Exception("left value must have  '" + Lib::TYPES::BROWSER + "'type, not '" + head->leftChild->token.type + "'"); return 0; }
	ProcessDictionary* pd = ProcessDictionary::getProcessDict();
	if (pd->get(tok.value) == nullptr) { throw Exception("no browser handle with value '" + tok.value = "'"); return 0; }
	if (head->leftChild->leftChild != nullptr || head->leftChild->rightChild != nullptr) { throw Exception("too much parameters"); return 0; }
	tok = head->rightChild->token;
	if (head->rightChild->token.type == Lib::TYPES::ID)
	{
		tok = vd->get(head->rightChild->token.value);
	}
	if (tok.type != Lib::TYPES::STR) { throw Exception("right value must have  '" + Lib::TYPES::STR + "'type, not '" + tok.type + "'");  return 0; }
	if (head->rightChild->leftChild != nullptr || head->rightChild->rightChild != nullptr) { throw Exception("too much parameters"); return 0; return 0; }
	return 1;
}


bool WebTreePatterns::compareForClick_Clear(Node* head)
{
	VarDictionary* vd = VarDictionary::getVarDict();
	if (head->leftChild == nullptr) { throw Exception("left value for '" + head->leftChild->token.value + "' is abscent"); return 0; }
	if (head->rightChild == nullptr) { throw Exception("right value for '" + head->rightChild->token.value + "' is abscent"); return 0; }
	Token tok = head->leftChild->token;
	if (head->leftChild->token.type != Lib::TYPES::ID) { throw Exception("left value must have  '" + Lib::TYPES::ID + "'type, not '" + head->leftChild->token.type + "'"); return 0; }
	tok = vd->get(head->leftChild->token.value);
	if (tok.type != Lib::TYPES::BROWSER) { throw Exception("left value must have  '" + Lib::TYPES::BROWSER + "'type, not '" + tok.type + "'"); return 0; }
	ProcessDictionary* pd = ProcessDictionary::getProcessDict();
	if (pd->get(tok.value) == nullptr) { throw Exception("no browser handle with value '" + tok.value = "'"); return 0; }
	if (head->leftChild->leftChild != nullptr || head->leftChild->rightChild != nullptr) { throw Exception("too much parameters"); return 0; }
	tok = head->rightChild->token;
	if (head->rightChild->token.type != Lib::TYPES::RESERVED) { throw Exception("right value must have  '" + Lib::TYPES::RESERVED + "'type, not '" + head->rightChild->token.type + "'"); return 0; }
	if (head->rightChild->token.value != "name" && head->rightChild->token.value != "id") { throw Exception("left value must be  '" + Lib::WEB::BROWSERS::CHROME + "' or '" + "', not '" + head->rightChild->token.value + "'"); ; return 0; }
	if (head->rightChild->leftChild != nullptr) { throw Exception("too much parameters"); return 0; }
	if (head->rightChild->rightChild == nullptr) { throw Exception("too less parameters"); return 0; }
	tok = head->rightChild->rightChild->token;
	if (head->rightChild->rightChild->token.type == Lib::TYPES::ID)
	{
		tok = vd->get(head->rightChild->rightChild->token.value);
	}
	if (tok.type != Lib::TYPES::STR) { throw Exception("right value must have  '" + Lib::TYPES::STR + "'type, not '" + tok.type + "'");  return 0; }
	if (head->rightChild->rightChild->leftChild != nullptr || head->rightChild->rightChild->rightChild != nullptr) { throw Exception("too much parameters"); return 0; }
	return 1;
}

bool WebTreePatterns::compareForInput(Node* head)
{
	VarDictionary* vd = VarDictionary::getVarDict();
	if (head->leftChild == nullptr) { throw Exception("left value for '" + head->leftChild->token.value + "' is abscent"); return 0; }
	if (head->rightChild == nullptr) { throw Exception("right value for '" + head->rightChild->token.value + "' is abscent"); return 0; }
	Token tok = head->leftChild->token;
	if (head->leftChild->token.type != Lib::TYPES::ID) { throw Exception("left value must have  '" + Lib::TYPES::ID + "'type, not '" + head->leftChild->token.type + "'"); return 0; }
	tok = vd->get(head->leftChild->token.value);
	if (tok.type != Lib::TYPES::BROWSER) { throw Exception("left value must have  '" + Lib::TYPES::BROWSER + "'type, not '" + tok.type + "'"); return 0; }
	ProcessDictionary* pd = ProcessDictionary::getProcessDict();
	if (pd->get(tok.value) == nullptr) { throw Exception("no browser handle with value '" + tok.value = "'"); return 0; }
	if (head->leftChild->leftChild != nullptr || head->leftChild->rightChild != nullptr) { throw Exception("too much parameters"); return 0; }
	tok = head->rightChild->token;
	if (head->rightChild->token.type != Lib::TYPES::RESERVED) { throw Exception("right value must have  '" + Lib::TYPES::RESERVED + "'type, not '" + head->rightChild->token.type + "'"); return 0; }
	if (head->rightChild->token.value != "name" && head->rightChild->token.value != "id") { throw Exception("left value must be  '" + Lib::WEB::BROWSERS::CHROME + "' or '" + "', not '" + head->rightChild->token.value + "'"); ; return 0; }
	if (head->rightChild->leftChild != nullptr) { throw Exception("too much parameters"); return 0; }
	if (head->rightChild->rightChild == nullptr) { throw Exception("too less parameters"); return 0; }
	tok = head->rightChild->rightChild->token;
	if (head->rightChild->rightChild->token.type == Lib::TYPES::ID)
	{
		tok = vd->get(head->rightChild->rightChild->token.value);
		cout << 120 <<endl;
	}
	if (tok.type != Lib::TYPES::STR) { throw Exception("right value must have  '" + Lib::TYPES::STR + "'type, not '" + tok.type + "'");  return 0; }
	if (head->rightChild->rightChild->leftChild != nullptr ) { throw Exception("too much parameters"); return 0; }
	if (head->rightChild->rightChild->rightChild == nullptr) { throw Exception("too less parameters"); return 0; }
	if (head->rightChild->rightChild->rightChild->token.type == Lib::TYPES::ID)
	{
		tok = vd->get(head->rightChild->rightChild->rightChild->token.value);
	}
	if (tok.type != Lib::TYPES::STR) { throw Exception("right value must have  '" + Lib::TYPES::STR + "'type, not '" + tok.type + "'");  return 0; }
	if (head->rightChild->rightChild->rightChild->leftChild != nullptr || head->rightChild->rightChild->rightChild->rightChild != nullptr) { throw Exception("too much parameters"); return 0; }


}


namespace performers
{
	
	namespace unop
	{

		void run(Node* node)
		{
			if (WebTreePatterns::compareForRun(node)) {
				InterProcessCommunicator* ipc = new InterProcessCommunicator();
				Lib::WEB::processCounter++;
				string name = "Globalfmo";
				name += to_string(Lib::WEB::processCounter);
				ipc->init(name);
				ProcessDictionary* pd = ProcessDictionary::getProcessDict();
				Process* pr = new Process(ipc);
				pr->buf.push_back("run$" + node->rightChild->token.value);
				pd->push(name, pr);
				node->token = Token(name, Lib::TYPES::BROWSER, Lib::VAR_prt);
				delete node->rightChild;
				node->rightChild = nullptr;
			}
		}
		void qiut(Node*node)
		{
			if (WebTreePatterns::compareForQuit(node))
			{
				VarDictionary* vd = VarDictionary::getVarDict();
				ProcessDictionary* pd = ProcessDictionary::getProcessDict();
				varConverter(node->leftChild);
				pd->get(node->leftChild->token.value)->buf.push_back("quit");
			}
		}
	}
	namespace binop
	{
		void open(Node* node)
		{
			if (WebTreePatterns::compareForOpen) {
				if (node->rightChild->token.type == Lib::TYPES::ID)
				{
					performers::varConverter(node->rightChild);
				}
				performers::varConverter(node->leftChild);
				ProcessDictionary* pd = ProcessDictionary::getProcessDict();
				pd->get(node->leftChild->token.value)->buf.push_back("open$" + node->rightChild->token.value);
				node->eraseChildren();
				//node = nullptr;
				/*delete node->rightChild;
				node->rightChild = nullptr;
				delete node->leftChild;
				node->leftChild = nullptr;*/
			}
		}

		void click(Node* node)
		{
			if (WebTreePatterns::compareForClick_Clear(node))
			{
				performers::varConverter(node->leftChild);
				ProcessDictionary* pd = ProcessDictionary::getProcessDict();
				pd->get(node->leftChild->token.value)->buf.push_back("click$" + node->rightChild->token.value + "$" + node->rightChild->rightChild->token.value);
				node->eraseChildren();
				node = nullptr;
				/*delete node->leftChild;
				node->leftChild = nullptr;
				delete node->rightChild->rightChild;
				node->rightChild->rightChild = nullptr;
				delete node->rightChild;
				node->rightChild = nullptr;*/
			}
		}

		void clear(Node* node)
		{
			if (WebTreePatterns::compareForClick_Clear(node))
			{
				performers::varConverter(node->leftChild);
				ProcessDictionary* pd = ProcessDictionary::getProcessDict();
				pd->get(node->leftChild->token.value)->buf.push_back("clear$" + node->rightChild->token.value + "$" + node->rightChild->rightChild->token.value);
				node->eraseChildren();
				node = nullptr;
				/*delete node->leftChild;
				node->leftChild = nullptr;
				delete node->rightChild->rightChild;
				node->rightChild->rightChild = nullptr;
				delete node->rightChild;
				node->rightChild = nullptr;*/
			}
		}

		void input(Node* node)
		{
			if (WebTreePatterns::compareForInput(node))
			{
				performers::varConverter(node->leftChild);
				ProcessDictionary* pd = ProcessDictionary::getProcessDict();
				if (node->rightChild->rightChild->rightChild->token.type == Lib::TYPES::ID) varConverter(node->rightChild->rightChild->rightChild);
				pd->get(node->leftChild->token.value)->buf.push_back("input$" + node->rightChild->token.value + "$" + node->rightChild->rightChild->token.value + "$" + node->rightChild->rightChild->rightChild->token.value);
				node->eraseChildren();
				node = nullptr;
				/*delete node->leftChild;
				node->leftChild = nullptr;
				delete node->rightChild->rightChild->rightChild;
				node->rightChild->rightChild->rightChild = nullptr;
				delete node->rightChild->rightChild;
				node->rightChild->rightChild = nullptr;
				delete node->rightChild;
				node->rightChild = nullptr;*/
			}
		}
	}
}