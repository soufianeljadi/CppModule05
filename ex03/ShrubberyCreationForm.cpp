#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Default")
{
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & src) : AForm(src), _target(src._target)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm & rhs)
{
    std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->_target = rhs._target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!this->getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    
    std::ofstream ofs((this->_target + "_shrubbery").c_str());
    if (!ofs)
    {
        std::cerr << "Error: could not open file" << std::endl;
        return;
    }
    ofs << "\n\n            _{\\ _{\\{\\/}/}/}__\n";
    ofs << "             {/{/\\}{/{/\\}(\\}{/\\} _\n";
    ofs << "            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _\n";
    ofs << "         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}\n";
    ofs << "        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}\n";
    ofs << "       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}\n";
    ofs << "      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}\n";
    ofs << "      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}\n";
    ofs << "     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}\n";
    ofs << "      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}\n";
    ofs << "       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)\n";
    ofs << "      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}\n";
    ofs << "       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}\n";
    ofs << "         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}\n";
    ofs << "          (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)\n";
    ofs << "            {/{/{\\{\\/}{/{\\{\\{\\(_)/}\n";
    ofs << "             {/{\\{\\{\\/}/}{\\{\\\\}/}\n";
    ofs << "              {){/ {\\/}{\\/} \\}\\}\n";
    ofs << "              (_)  \\.-'.-/\n";
    ofs << "          __...--- |'-.-'| --...__\n";
    ofs << "   _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__\n";
    ofs << " -\"    ' .  . '    |.'-._| '  . .  '   ben10\n";
    ofs << " .  '-  '    .--'  | '-.'|    .  '  . '\n";
    ofs << "          ' ..     |'-_.-|\n";
    ofs << "  .  '  .       _.-|-._ -|-._  .  '  .\n";
    ofs << "              .'   |'- .-|   '.\n";
    ofs << "  ..-'   ' .  '.   `-._.-´   .'  '  - .\n";
    ofs << "   .-' '        '-._______.-'     '  .\n";
    ofs << "        .      ~,\n";
    ofs.close();
}

std::string ShrubberyCreationForm::getTarget() const
{
    return this->_target;
}

std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const & src)
{
    o << "ShrubberyCreationForm: " << src.getName() << ", target: " << src.getTarget() << ", is signed: " << src.getIsSigned() << ", grade to sign: " << src.getGradeToSign() << ", grade to execute: " << src.getGradeToExecute();
    return o;
}
