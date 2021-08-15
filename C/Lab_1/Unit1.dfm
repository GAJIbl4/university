object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 324
  ClientWidth = 299
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 74
    Top = 8
    Width = 147
    Height = 19
    Caption = #1048#1089#1093#1086#1076#1085#1099#1081' '#1084#1072#1089#1089#1080#1074
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 48
    Top = 224
    Width = 193
    Height = 13
    Caption = #1050#1086#1086#1088#1076#1080#1085#1072#1090#1099' '#1084#1072#1082#1089#1080#1084#1072#1083#1100#1085#1086#1075#1086' '#1101#1083#1077#1084#1077#1085#1090#1072
  end
  object Label3: TLabel
    Left = 70
    Top = 247
    Width = 25
    Height = 13
    Caption = #1056#1103#1076
  end
  object Label4: TLabel
    Left = 200
    Top = 247
    Width = 37
    Height = 13
    Caption = #1057#1090#1088#1086#1082#1072
  end
  object StringGrid1: TStringGrid
    Left = 32
    Top = 33
    Width = 233
    Height = 177
    ColCount = 7
    DefaultColWidth = 32
    FixedCols = 0
    RowCount = 7
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    ScrollBars = ssNone
    TabOrder = 0
    ColWidths = (
      32
      32
      32
      32
      32
      32
      32)
    RowHeights = (
      24
      24
      24
      24
      24
      24
      24)
  end
  object Button1: TButton
    Left = 64
    Top = 293
    Width = 75
    Height = 25
    Caption = #1056#1072#1085#1076#1086#1084
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 154
    Top = 293
    Width = 75
    Height = 25
    Caption = #1042#1099#1087#1086#1083#1085#1080#1090#1100
    TabOrder = 2
    OnClick = Button2Click
  end
  object Edit1: TEdit
    Left = 32
    Top = 266
    Width = 97
    Height = 21
    TabOrder = 3
  end
  object Edit2: TEdit
    Left = 168
    Top = 266
    Width = 97
    Height = 21
    TabOrder = 4
  end
end
