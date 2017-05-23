/*
 * SaveSVGInterface.h
 *
 *  Created on: 04.11.2009
 *      Author: Trinity
 */

#ifndef SAVESVGINTERFACE_H_
#define SAVESVGINTERFACE_H_

class SaveSVGInterface: public QWidget
{
	public:

		/**
		*	�����������.
		*/
		SaveSVGInterface(){}

		/**
		*	����������.
		*/
		virtual ~SaveSVGInterface(){}

		virtual bool SaveFile(QString to) = 0;
};

/**
 * ���������� ����������
 */
Q_DECLARE_INTERFACE( SaveSVGInterface, "ifmo.lothe.SaveSVGInterface/1.0" )


/**
*	�������� ��������� �� ����� ������ � ���������� �� ��������� SaveSVGInterface.
*
*	@return ���������� ��������� ��� 0, ���� ��������� ������.
*/
template < class T > inline SaveSVGInterface* SAVESVG( T *o )
{
	return qobject_cast< SaveSVGInterface* >( o );
}

#endif /* SAVESVGINTERFACE_H_ */
