/*
 * ContextHelpInterface.h
 *
 *  Created on: 18.04.2009
 *      Author: Trinity
 */

#ifndef CONTEXTHELPINTERFACE_H_
#define CONTEXTHELPINTERFACE_H_

class ContextHelpInterface: public QWidget
{
	public:

		/**
		 * �����, ������������ ���������� �������.
		 */
		virtual void show() = 0;

		/**
		 * �����, ������������ ����������� �������
		 * ��� �������� ��������� ��������.
		 */
		virtual void showContext() = 0;

		/**
		*	�����������.
		*/
		ContextHelpInterface(){}

		/**
		*	����������.
		*/
		virtual ~ContextHelpInterface(){}
};

/**
 * ���������� ����������
 */
Q_DECLARE_INTERFACE( ContextHelpInterface, "ifmo.lothe.ContextHelpInterface/1.0" )


/**
*	�������� ��������� �� ����� ������ � ���������� �� ��������� SaveSVGInterface.
*
*	@return ���������� ��������� ��� 0, ���� ��������� ������.
*/
template < class T > inline ContextHelpInterface* CONTEXTHELP( T *o )
{
	return qobject_cast< ContextHelpInterface* >( o );
}

#endif /* CONTEXTHELPINTERFACE_H_ */
